using lab2.Settings;
using System.Windows;

namespace TimerMVVM
{
    /// <summary>
    /// Interaction logic for TimerSettings.xaml
    /// </summary>
    public partial class TimerSettings : Window, ISettings<TimerModel>
    {
        private TimerModel _timerModelToFill;
        public TimerSettings()
        {
            InitializeComponent();
        }

        private void ApplyBtn_Click(object sender, RoutedEventArgs e)
        {
            int hour, minute, second;
            bool parsedHour, parsedMinute, parsedSecond;
            parsedHour = int.TryParse(HoursInput.Text.ToString(), out hour);
            parsedMinute = int.TryParse(MinutesInput.Text.ToString(), out minute);
            parsedSecond = int.TryParse(SecondsInput.Text.ToString(), out second);
            if (parsedHour && parsedMinute && parsedSecond && hour >= 0 && hour < 24
                && minute >= 0 && minute <= 59 && second >= 0 && second <= 59)
            {
                _timerModelToFill.Hour = hour;
                _timerModelToFill.Minute = minute;
                _timerModelToFill.Second = second;
                _timerModelToFill.Active = true;
            }
            else
            {
                MessageBox.Show("Something went wrong!");
            }
            this.Hide();
        }
        public void FillData(TimerModel model)
        {
            _timerModelToFill = model;
            this.Show();
        }

        private void CancelBtn_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
            _timerModelToFill.Active = true;
        }
    }
}
