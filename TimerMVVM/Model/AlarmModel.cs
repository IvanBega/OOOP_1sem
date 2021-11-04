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
    }
}
