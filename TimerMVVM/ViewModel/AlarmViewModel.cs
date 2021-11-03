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
    [Serializable]
    public class AlarmViewModel
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
            UpdateView(new object(), new EventArgs());
        }
        private void DeleteBtn_Click(object s, RoutedEventArgs e)
        {
            _alarmModel.Active = false;
            _alarmView.RemoveFromStackPanel();
            MainWindow wnd = (MainWindow)Application.Current.MainWindow;
            wnd.RemoveAlarmFromList(this);
        }
        private void EditBtn_Click(object s, RoutedEventArgs e)
        {
            _alarmSettings.FillData(_alarmModel);
        }
        public void UpdateView(object sender, EventArgs e)
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
        public void SetDelBtnVisibility(Visibility option)
        {
            _alarmView.SetDelBtnVisibility(option);
        }
        public void CloseSettingsWindow()
        {
            _alarmSettings.Close();
        }
        public void PlayTimerSound(object s, DoWorkEventArgs e)
        {

            using SoundPlayer soundPlayer = new(@"D:\Программирование\CSharp\WPF\TestApp\TestApp\Sounds\Sound1.mp3");
            soundPlayer.Play();
        }
        public bool IsActive()
        {
            return _alarmModel.Active;
        }
        public void Check()
        {
            int hourNow = DateTime.Now.Hour;
            int minuteNow = DateTime.Now.Minute;
            int dayNow = (int) DateTime.Now.DayOfWeek;
            if (_alarmSettings.TheList[dayNow].IsSelected && hourNow == _alarmModel.Hour && minuteNow == _alarmModel.Minute)
            {
                _alarmModel.Active = false;
                MessageBox.Show(String.Format("Now is {0}:{1}", _alarmModel.Hour, _alarmModel.Minute));          
            }
        }

        public AlarmModel GetModel()
        {
            return _alarmModel;
        }
    }
}
