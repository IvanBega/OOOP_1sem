using System.Windows;
using System.Windows.Controls;

namespace TimerMVVM
{
    public class Timer : BaseView
    {
        private Button _pauseBtn;
        public Timer(StackPanel mainPanel, RoutedEventHandler editBtnHandler, RoutedEventHandler delBtnHandler,
            RoutedEventHandler pauseBtnHandler) :
            base(mainPanel, editBtnHandler, delBtnHandler)
        {
            _pauseBtn = new Button
            {
                Height = 50,
                Width = 50,
                Content = "Pause",
            };
            _label.Content = "00:00:00";
            _label.Width = 130;
            _controlsPanel.Width = 300;
            _pauseBtn.Click += pauseBtnHandler;

            _controlsPanel.Children.Add(_pauseBtn);
            _controlsPanel.Children.Add(_deleteBtn);
            _mainPanel.Children.Add(_controlsPanel);
        }
        private void InitializeComponents(RoutedEventHandler editBtnHandler, RoutedEventHandler delBtnHandler,
            RoutedEventHandler pauseBtnHandler)
        {
            _label = new Label
            {
                Content = "00:00:00",
                Height = 50,
                Width = 130,
                FontSize = 30,
            };
            _deleteBtn = new Button
            {
                Height = 50,
                Width = 50,
                Content = "Delete",
                Visibility = DelBtnVisibility
            };
            _editBtn = new Button
            {
                Height = 50,
                Width = 50,
                Content = "Edit",
            };
            _pauseBtn = new Button
            {
                Height = 50,
                Width = 50,
                Content = "Pause",
            };
            _controlsPanel = new StackPanel() { Orientation = Orientation.Horizontal, Height = 100, Width = 300 };
            _deleteBtn.Click += delBtnHandler;
            _editBtn.Click += editBtnHandler;
            _pauseBtn.Click += pauseBtnHandler;

            _controlsPanel.Children.Add(_label);
            _controlsPanel.Children.Add(_editBtn);
            _controlsPanel.Children.Add(_pauseBtn);
            _controlsPanel.Children.Add(_deleteBtn);
            _mainPanel.Children.Add(_controlsPanel);
        }
    }
}
