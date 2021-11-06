using System;
using System.ComponentModel;
using System.Media;
using System.Runtime.Serialization;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Xml.Serialization;

namespace TimerMVVM
{
    public class AlarmViewModel : BaseViewModel
    {
        private AlarmModel _alarmModel;
        private Alarm _alarmView;
        private AlarmSettings _alarmSettings = new();
        public AlarmViewModel()
        {

        }
        public AlarmViewModel(StackPanel panel)
        {
            _alarmModel = new();
            _alarmView = new(panel, new RoutedEventHandler(EditBtn_Click), new RoutedEventHandler(DeleteBtn_Click));
            _alarmSettings.ValueChanged += UpdateView;
        }
        public AlarmViewModel(StackPanel panel,  AlarmModel model)
        {
            _alarmModel = model;
            _alarmView = new(panel, new RoutedEventHandler(EditBtn_Click), new RoutedEventHandler(DeleteBtn_Click));
            _alarmSettings.ValueChanged += UpdateView;
            UpdateView();
        }
        protected override void DeleteBtn_Click(object s, RoutedEventArgs e)
        {
            _alarmModel.Active = false;
            _alarmView.RemoveFromStackPanel();
            MainWindow wnd = (MainWindow)Application.Current.MainWindow;
            wnd.RemoveAlarmFromList(this);
            wnd.AlarmStackPanel.Height -= 100;
            if (wnd.AlarmsCount() >= 3)
            {
                wnd.AlarmCanvas.Height -= 100;
            }
        }
        protected override void EditBtn_Click(object s, RoutedEventArgs e)
        {
            _alarmSettings.FillData(_alarmModel);
        }
        protected override void UpdateView()
        {
            StringBuilder sb = new();
            if (_alarmModel.Hour < 10)
                sb.Append("0");
            sb.Append(_alarmModel.Hour);
            sb.Append(':');
            if (_alarmModel.Minute < 10)
                sb.Append('0');
            sb.Append(_alarmModel.Minute);
            _alarmView.SetTime(sb.ToString());
        }
        public override void SetDelBtnVisibility(Visibility option)
        {
            _alarmView.SetDelBtnVisibility(option);
        }
        public override void CloseSettingsWindow()
        {
            _alarmSettings.Close();
        }
        public override bool IsActive()
        {
            return _alarmModel.Active;
        }
        public override void DoLogic()
        {
            int hourNow = DateTime.Now.Hour;
            int minuteNow = DateTime.Now.Minute;
            int dayNow = (int) DateTime.Now.DayOfWeek;
            if (_alarmSettings.TheList[dayNow].IsSelected && hourNow == _alarmModel.Hour && minuteNow == _alarmModel.Minute)
            {
                Activate();       
            }
        }
        protected override void Activate()
        {
            _alarmModel.Active = false;
            Notify("Your alarm is active!");
        }
        public AlarmModel GetModel()
        {
            return _alarmModel;
        }
        public void SetControlsPanelVisibility(Visibility option)
        {
            _alarmView.SetControlsPanelVisibility(option);
        }
    }
}
