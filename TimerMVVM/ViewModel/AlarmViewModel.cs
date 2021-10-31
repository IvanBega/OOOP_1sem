using System;
using System.ComponentModel;
using System.Media;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace TimerMVVM
{
    public class AlarmViewModel
    {
        private AlarmModel _alarmModel = new();
        private Alarm _alarmView;
        private AlarmSettings _alarmSettings = new();
        private int _hourNow;
        private int _minuteNow;
        public AlarmViewModel(StackPanel panel)
        {
            _alarmView = new(panel, new RoutedEventHandler(EditBtn_Click), new RoutedEventHandler(DeleteBtn_Click));
            _alarmSettings.ValueChanged += UpdateView;
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
            _hourNow = DateTime.Now.Hour;
            _minuteNow = DateTime.Now.Minute;
            if (_hourNow == _alarmModel.Hour && _minuteNow == _alarmModel.Minute)
            {
                MessageBox.Show(String.Format("Now is {0}:{1}", _alarmModel.Hour, _alarmModel.Minute));
                _alarmModel.Active = false;
            }
        }
    }
}
