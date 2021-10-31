using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Threading.Tasks;
using System.Windows;

namespace TimerMVVM
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private List<AlarmViewModel> _alarmList = new();
        private List<TimerViewModel> _timerList = new();
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
            while (true)
            {
                foreach (var t in _timerList)
                {
                    if (t.IsActive())
                    {
                        t.SubtractSecond();
                    }
                }
                await Task.Delay(500);
            }
        }
        private async void AlarmLogic()
        {
            while (true)
            {
                foreach (var a in _alarmList)
                {
                    a.Check();
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
    }
}
