﻿#pragma checksum "..\..\..\AlarmSettings.xaml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "5FF73D0E58E97CEEB6295DB7590D652BC231861F"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.42000
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Controls.Ribbon;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Shell;
using TimerMVVM;


namespace TimerMVVM {
    
    
    /// <summary>
    /// AlarmSettings
    /// </summary>
    public partial class AlarmSettings : System.Windows.Window, System.Windows.Markup.IComponentConnector {
        
        
        #line 12 "..\..\..\AlarmSettings.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox HoursInput;
        
        #line default
        #line hidden
        
        
        #line 16 "..\..\..\AlarmSettings.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox MinutesInput;
        
        #line default
        #line hidden
        
        
        #line 20 "..\..\..\AlarmSettings.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.TextBox CaptionInput;
        
        #line default
        #line hidden
        
        
        #line 22 "..\..\..\AlarmSettings.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.CheckBox IsActive;
        
        #line default
        #line hidden
        
        
        #line 31 "..\..\..\AlarmSettings.xaml"
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1823:AvoidUnusedPrivateFields")]
        internal System.Windows.Controls.Button ApplyBtn;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "5.0.11.0")]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/lab2;component/alarmsettings.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\..\AlarmSettings.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.CodeDom.Compiler.GeneratedCodeAttribute("PresentationBuildTasks", "5.0.11.0")]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Performance", "CA1800:DoNotCastUnnecessarily")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.HoursInput = ((System.Windows.Controls.TextBox)(target));
            return;
            case 2:
            this.MinutesInput = ((System.Windows.Controls.TextBox)(target));
            return;
            case 3:
            this.CaptionInput = ((System.Windows.Controls.TextBox)(target));
            return;
            case 4:
            this.IsActive = ((System.Windows.Controls.CheckBox)(target));
            
            #line 22 "..\..\..\AlarmSettings.xaml"
            this.IsActive.Checked += new System.Windows.RoutedEventHandler(this.IsActive_Checked);
            
            #line default
            #line hidden
            return;
            case 5:
            this.ApplyBtn = ((System.Windows.Controls.Button)(target));
            
            #line 31 "..\..\..\AlarmSettings.xaml"
            this.ApplyBtn.Click += new System.Windows.RoutedEventHandler(this.ApplyBtn_Click);
            
            #line default
            #line hidden
            return;
            }
            this._contentLoaded = true;
        }
    }
}

