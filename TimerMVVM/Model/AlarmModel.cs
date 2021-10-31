using System;

namespace TimerMVVM
{
    public class AlarmModel
    {
        public int Hour { get; set; } = 0;
        public int Minute { get; set; } = 0;
        public string TimeString { get; set; } = String.Empty;
        public string Caption { get; set; } = String.Empty;
        public bool Active { get; set; } = false;
    }
}
