   M S B A M L   `   `   `  ����?  ;lab2, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null%clr-namespace:TimerMVVM	TimerMVVM  5   	       TimerMVVM.AlarmSettings   5   	   W SPresentationCore, Version=5.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=5.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=5.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=5.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=5.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   )localclr-namespace:TimerMVVM     5   	     � Title$  AlarmSettings��5   	   $	��350��6   $	��200��6,    � WindowStyle$
 None=�68   .��5	      �� .+�5
   
   �� $��40��6   $	��200��6!    �� Orientation$ 
Horizontal=�6-   .+�5      �� $��Hours:��6   $��26(�6&   $��40��64   $��80��6@   6M   �� 5      -   5        $��
HoursInput��5      $��26(�6)   $��40��67   $��80��6C   6P   5      �� 5   
   $��40��6   $ 
Horizontal=�6!   .+�5      �� $��Mins:��6   $��26(�6%   $��40��63   $��80��6?   6L   �� 5      -   5        $��MinutesInput��5      $��26(�6+   $��40��69   $��80��6E   6R   5      �� 5   
   -   5        $��IsActive��5      $��Active��6#   $��12(�64   6_   �� 5   
   $��40��6   $	��120��6    $��26(�6,   $��
Active on:��6:   �� 5   
   ��6   �� *	TheList+��5      �� 5      .R�5      ��  d� 	IsChecked 6   �� *
IsSelected+��6@   �� *	TheText+5      5      �� 5   
   -   5        $��ApplyBtn��5      $��Apply��6!   $	��100��62   $��30��6>   $��18(�6J   6q   �� 5   
   -   5        $��	CancelBtn��5      $��Cancel��6"   $	��100��64   $��30��6@   $��18(�6L   6t   5      5      