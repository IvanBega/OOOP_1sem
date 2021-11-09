using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text.Json;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
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
            TimerLoop();
            AlarmLoop();
        }

        public void RemoveTimerFromList(TimerViewModel t)
        {
            t.CloseSettingsWindow();
            _timerList.Remove(t);
        }
        private async void TimerLoop()
        {
            while (_windowActive)
            {
                foreach (var t in _timerList)
                {
                    if (t.IsActive())
                    {
                        t.DoLogic();
                    }
                }
                await Task.Delay(1000);
            }
        }
        private async void AlarmLoop()
        {
            while (_windowActive)
            {
                foreach (var a in _alarmList)
                {
                    if (a.IsActive())
                    {
                        a.DoLogic();
                    }
                }
                await Task.Delay(1000);
            }
        }

        private void AddAlarmBtn_Click(object sender, RoutedEventArgs e)
        {
            AlarmViewModel t = new(AlarmStackPanel);
            _alarmList.Add(t);
            AlarmStackPanel.Height += 100;
            if (AlarmsCount() > 3)
            {
                AlarmCanvas.Height += 100;
            }
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
            TimerStackPanel.Height += 100;
            if (TimersCount() > 3)
            {
                TimerCanvas.Height += 100;
            }
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
                    AlarmStackPanel.Height += 100;
                    if (AlarmsCount() > 3)
                    {
                        AlarmCanvas.Height += 100;
                    }
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
                    TimerStackPanel.Height += 100;
                    if (TimersCount() > 3)
                    {
                        TimerCanvas.Height += 100;
                    }
                }
            }

        }
        public int AlarmsCount()
        {
            return _alarmList.Count;
        }
        public int TimersCount()
        {
            return _timerList.Count;
        }

        private void AlarmComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox box = (ComboBox)sender;
            foreach (var a in _alarmList)
            {
                a.SetControlsPanelVisibility(Visibility.Visible);
            }
            switch (box.SelectedIndex)
            {
                case 1:
                    foreach (var a in _alarmList)
                    {
                        if (!a.IsActive())
                        {
                            a.SetControlsPanelVisibility(Visibility.Collapsed);
                        }
                    }
                    break;
                case 2:
                    foreach (var a in _alarmList)
                    {
                        if (a.IsActive())
                        {
                            a.SetControlsPanelVisibility(Visibility.Collapsed);
                        }
                    }
                    break;
            }
        }

        private void TimerComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ComboBox box = (ComboBox)sender;
            foreach (var t in _timerList)
            {
                t.SetControlsPanelVisibility(Visibility.Visible);
            }
            switch (box.SelectedIndex)
            {
                case 1:
                    foreach(var t in _timerList)
                    {
                        if (!t.IsActive())
                        {
                            t.SetControlsPanelVisibility(Visibility.Collapsed);
                        }
                    }
                    break;
                case 2:
                    foreach (var t in _timerList)
                    {
                        if (t.IsActive())
                        {
                            t.SetControlsPanelVisibility(Visibility.Collapsed);
                        }
                    }
                    break;
            }
        }
    }
}
