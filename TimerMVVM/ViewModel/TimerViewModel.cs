using System;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace TimerMVVM
{
    public class TimerViewModel : BaseViewModel
    {
        private Timer _timerView;
        private TimerModel _timerModel;
        private TimerSettings _timerSettings = new();
        public TimerViewModel(StackPanel panel)
        {
            _timerView = new Timer(panel, new RoutedEventHandler(EditBtn_Click), new RoutedEventHandler(DeleteBtn_Click),
                new RoutedEventHandler(PauseBtn_Click));
            _timerModel = new();
        }
        public TimerViewModel(StackPanel panel, TimerModel model)
        {
            _timerView = new Timer(panel, new RoutedEventHandler(EditBtn_Click), new RoutedEventHandler(DeleteBtn_Click),
                new RoutedEventHandler(PauseBtn_Click));
            _timerModel = model;
            UpdateView();
        }
        public override void CloseSettingsWindow()
        {
            _timerSettings.Close();
        }
        private void PauseBtn_Click(object sender, RoutedEventArgs e)
        {
            if (_timerModel.Active)
            {
                _timerModel.Active = false;
            }
            else if (!(_timerModel.Hour == 0 && _timerModel.Minute == 0 && _timerModel.Second == 0))
            {
                _timerModel.Active = true;
            }
        }
        private void UpdateView()
        {
            StringBuilder sb = new();
            if (_timerModel.Hour < 10)
            {
                sb.Append("0");
            }
            sb.Append(_timerModel.Hour);
            sb.Append(':');
            if (_timerModel.Minute < 10)
            {
                sb.Append("0");
            }
            sb.Append(_timerModel.Minute);
            sb.Append(":");
            if (_timerModel.Second < 10)
            {
                sb.Append('0');
            }
            sb.Append(_timerModel.Second);
            _timerView.SetTime(sb.ToString());
        }
        public override void DoLogic()
        {
            UpdateView();
            int time = _timerModel.Hour * 3600 + _timerModel.Minute * 60 + _timerModel.Second - 1;
            if (time >= 0)
            {
                _timerModel.Hour = time / 3600;
                time %= 3600;
                _timerModel.Minute = time / 60;
                time %= 60;
                _timerModel.Second = time;
            }
            else
            {
                Activate();
            }
        }
        protected override void DeleteBtn_Click(object sender, RoutedEventArgs e)
        {
            _timerView.RemoveFromStackPanel();
            MainWindow wnd = (MainWindow)Application.Current.MainWindow;
            wnd.RemoveTimerFromList(this);
            wnd.TimerStackPanel.Height -= 100;
            if (wnd.TimersCount() >= 3)
            {
                wnd.TimerCanvas.Height -= 100;
            }
        }

        protected override void EditBtn_Click(object sender, RoutedEventArgs e)
        {
            _timerModel.Active = false;
            _timerSettings.FillData(_timerModel);
        }

        public override void SetDelBtnVisibility(Visibility option)
        {
            _timerView.SetDelBtnVisibility(option);
        }
        public override bool IsActive()
        {
            return _timerModel.Active;
        }

        public TimerModel GetModel()
        {
            return _timerModel;
        }
        protected override void Activate()
        {
            _timerModel.Active = false;
            Notify("Your timer is active!");
        }

        public void SetControlsPanelVisibility(Visibility option)
        {
            _timerView.SetControlsPanelVisibility(option);
        }
    }
}
