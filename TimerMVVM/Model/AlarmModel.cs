using System;
using System.Collections.ObjectModel;

namespace TimerMVVM
{
    [Serializable]
    public class AlarmModel
    {
        public int Hour { get; set; } = 0;
        public int Minute { get; set; } = 0;
        public bool Active { get; set; } = false;
        public bool WasActiveToday { get; set; } = false;
    }
    public class BoolStringClass
    {
        public string TheText { get; set; }
        public bool IsSelected { get; set; }
    }
}
