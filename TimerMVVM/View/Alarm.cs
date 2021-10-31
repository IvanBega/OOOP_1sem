using System.Windows;
using System.Windows.Controls;

namespace TimerMVVM
{
    public class Alarm : BaseView
    {
        public Alarm(StackPanel mainPanel, RoutedEventHandler edBtnHandler, RoutedEventHandler delBtnHandler) :
            base(mainPanel, edBtnHandler, delBtnHandler)
        {
            _label.Content = "00:00";
            _label.Width = 100;
            _controlsPanel.Width = 200;

            _controlsPanel.Children.Add(_deleteBtn);
            _mainPanel.Children.Add(_controlsPanel);
        }
    }
}
