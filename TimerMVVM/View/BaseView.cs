using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace TimerMVVM
{
    public abstract class BaseView
    {
        protected Label _label;
        protected Button _editBtn;
        protected Button _deleteBtn;
        protected StackPanel _mainPanel;
        protected StackPanel _controlsPanel;
        public static Visibility DelBtnVisibility { get; set; } = Visibility.Hidden;
        public void SetTime(string time)
        {
            _label.Content = time;
        }
        public void SetDelBtnVisibility(Visibility option)
        {
            _deleteBtn.Visibility = option;
        }
        public BaseView(StackPanel mainPanel, RoutedEventHandler editBtnHandler, RoutedEventHandler delBtnHandler)
        {
            _mainPanel = mainPanel;
            InitializeComponents(editBtnHandler, delBtnHandler);
        }
        private void InitializeComponents(RoutedEventHandler editBtnHandler, RoutedEventHandler delBtnHandler)
        {
            _label = new Label
            {
                Height = 50,
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
            _controlsPanel = new() { Orientation = Orientation.Horizontal, Height = 100 };
            _deleteBtn.Click += delBtnHandler;
            _editBtn.Click += editBtnHandler;
            _controlsPanel.Children.Add(_label);
            _controlsPanel.Children.Add(_editBtn);
        }
        public void RemoveFromStackPanel()
        {
            _mainPanel.Children.Remove(_controlsPanel);
        }

    }
}
