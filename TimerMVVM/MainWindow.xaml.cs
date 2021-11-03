﻿using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows;
using System.Xml;
using System.Xml.Serialization;

namespace TimerMVVM
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private List<AlarmViewModel> _alarmList = new();
        private List<TimerViewModel> _timerList = new();
        private bool _windowActive = true;
        public MainWindow()
        {
            InitializeComponent();
            TimerLogic();
            AlarmLogic();
        }

        public void RemoveTimerFromList(TimerViewModel t)
        {
            t.CloseSettingsWindow();
            _timerList.Remove(t);
        }
        private async void TimerLogic()
        {
            while (_windowActive)
            {
                foreach (var t in _timerList)
                {
                    if (t.IsActive())
                    {
                        t.SubtractSecond();
                    }
                }
                await Task.Delay(1000);
            }
        }
        private async void AlarmLogic()
        {
            while (_windowActive)
            {
                foreach (var a in _alarmList)
                {
                    if (a.IsActive())
                    {
                        a.Check();
                    }
                }
                await Task.Delay(2000);
            }
        }

        private void AddAlarmBtn_Click(object sender, RoutedEventArgs e)
        {
            AlarmViewModel t = new(AlarmStackPanel);
            _alarmList.Add(t);
        }
        public void RemoveAlarmFromList(AlarmViewModel a)
        {
            a.CloseSettingsWindow();
            _alarmList.Remove(a);
        }

        private void MyWindow_Closed(object sender, EventArgs e)
        {
            foreach (AlarmViewModel a in _alarmList)
            {
                a.CloseSettingsWindow();
            }
            foreach (TimerViewModel t in _timerList)
            {
                t.CloseSettingsWindow();
            }
        }

        private void DelAlarmBtn_Click(object sender, RoutedEventArgs e)
        {
            Visibility option = Visibility.Visible;
            if (Alarm.DelBtnVisibility == Visibility.Visible)
            {
                Alarm.DelBtnVisibility = Visibility.Hidden;
                option = Visibility.Hidden;
            }
            else
            {
                Alarm.DelBtnVisibility = Visibility.Visible;
            }
            foreach (AlarmViewModel t in _alarmList)
            {
                t.SetDelBtnVisibility(option);
            }
        }

        private void AddTimerBtn_Click(object sender, RoutedEventArgs e)
        {
            TimerViewModel t = new(TimerStackPanel);
            _timerList.Add(t);
        }

        private void DelTimerBtn_Click(object sender, RoutedEventArgs e)
        {
            Visibility option = Visibility.Visible;
            if (Timer.DelBtnVisibility == Visibility.Visible)
            {
                Timer.DelBtnVisibility = Visibility.Hidden;
                option = Visibility.Hidden;
            }
            else
            {
                Timer.DelBtnVisibility = Visibility.Visible;
            }
            foreach (TimerViewModel t in _timerList)
            {
                t.SetDelBtnVisibility(option);
            }
        }

        private void MyWindow_Closing(object sender, CancelEventArgs e)
        {
            _windowActive = false;
            List<AlarmModel> alarmList = new();
            foreach(var a in _alarmList)
            {
                alarmList.Add(a.GetModel());
            }
            SaveListAsXmlFormat<AlarmModel>(alarmList, "Alarms.xml");

            List<TimerModel> timerList = new();
            foreach (var t in _timerList)
            {
                timerList.Add(t.GetModel());
            }
            SaveListAsXmlFormat<TimerModel>(timerList, "Timers.xml");
        }

        private void SaveListAsXmlFormat<T>(List<T> list, string fileName)
        {
            XmlSerializer xmlFormat = new XmlSerializer(typeof(List<T>));
            using (Stream fStream = new FileStream(fileName,
            FileMode.Create, FileAccess.Write, FileShare.None))
            {
                xmlFormat.Serialize(fStream, list);
            }
        }

        private T ReadListAsXmlFormat<T>(string fileName)
        {
            XmlSerializer xmlFormat = new XmlSerializer(typeof(T));
            using (Stream fStream = new FileStream(fileName, FileMode.Open))
            {
                T obj = default;
                obj = (T)xmlFormat.Deserialize(fStream);
                return obj;
            }
        }

        private void MyWindow_Initialized(object sender, EventArgs e)
        {
            List<AlarmModel> alarmModels = new();
            if (File.Exists("Alarms.xml"))
            {
                alarmModels = ReadListAsXmlFormat<List<AlarmModel>>("Alarms.xml");
                foreach (var a in alarmModels)
                {
                    AlarmViewModel avm = new(AlarmStackPanel, a);
                    _alarmList.Add(avm);
                }
            }


            List<TimerModel> timerModels = new();
            if (File.Exists("Timers.xml"))
            {
                timerModels = ReadListAsXmlFormat<List<TimerModel>>("Timers.xml");
                foreach (var t in timerModels)
                {
                    TimerViewModel tvm = new(TimerStackPanel, t);
                    _timerList.Add(tvm);
                }
            }

        }
    }
}
