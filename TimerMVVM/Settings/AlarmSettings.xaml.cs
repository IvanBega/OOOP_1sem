using lab2.Settings;
using System;
using System.Collections.ObjectModel;
using System.Text;
using System.Windows;

namespace TimerMVVM
{
    /// <summary>
    /// Interaction logic for AlarmSettings.xaml
    /// </summary>
    public partial class AlarmSettings : Window, ISettings<AlarmModel>
    {
        public ObservableCollection<BoolStringClass> TheList { get; private set; }
        private AlarmModel _alarmModelToFill;
        public event Action ValueChanged;
        public AlarmSettings()
        {
            InitializeComponent();
            TheList = new ObservableCollection<BoolStringClass>
            {
                new BoolStringClass { IsSelected = true, TheText = "Sunday" },
                new BoolStringClass { IsSelected = true, TheText = "Monday" },
                new BoolStringClass { IsSelected = true, TheText = "Tueday" },
                new BoolStringClass { IsSelected = true, TheText = "Wednesday" },
                new BoolStringClass { IsSelected = true, TheText = "Thursday" },
                new BoolStringClass { IsSelected = true, TheText = "Friday" },
                new BoolStringClass { IsSelected = true, TheText = "Saturday" }
            };
            this.DataContext = this;
        }

        private void ApplyBtn_Click(object sender, RoutedEventArgs e)
        {
            int hour, minute;
            bool parsedHour, parsedMinute;
            parsedHour = int.TryParse(HoursInput.Text.ToString(), out hour);
            parsedMinute = int.TryParse(MinutesInput.Text.ToString(), out minute);

            if (parsedHour && parsedMinute && hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
            {   
                _alarmModelToFill.Hour = hour;
                _alarmModelToFill.Minute = minute;
                _alarmModelToFill.Active = IsActive.IsChecked ?? false;
                ValueChanged?.Invoke();
            }
            else
            {
                MessageBox.Show("Something went wrong!");
            }
            this.Hide();
        }
        public void FillData(AlarmModel model)
        {
            IsActive.IsChecked = model.Active;
            _alarmModelToFill = model;
            this.Show();
        }
        private void IsActive_Checked(object sender, RoutedEventArgs e)
        {

        }
        private void CancelBtn_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
        }
    }
    public class BoolStringClass
    {
        public string TheText { get; set; }
        public bool IsSelected { get; set; }
    }
}
