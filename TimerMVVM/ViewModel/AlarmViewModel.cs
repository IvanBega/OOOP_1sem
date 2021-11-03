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
            UpdateView(new object(), new EventArgs());
        }
        protected override void DeleteBtn_Click(object s, RoutedEventArgs e)
        {
            _alarmModel.Active = false;
            _alarmView.RemoveFromStackPanel();
            MainWindow wnd = (MainWindow)Application.Current.MainWindow;
            wnd.RemoveAlarmFromList(this);
        }
        protected override void EditBtn_Click(object s, RoutedEventArgs e)
        {
            _alarmSettings.FillData(_alarmModel);
        }
        private void UpdateView(object sender, EventArgs e)
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
        public void PlayTimerSound(object s, DoWorkEventArgs e)
        {

            using SoundPlayer soundPlayer = new(@"D:\Программирование\CSharp\WPF\TestApp\TestApp\Sounds\Sound1.mp3");
            soundPlayer.Play();
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
            MessageBox.Show("Your timer is active!");
        }
        public AlarmModel GetModel()
        {
            return _alarmModel;
        }
    }
}
