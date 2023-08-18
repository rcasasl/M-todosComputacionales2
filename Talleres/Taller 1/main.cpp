int main ()
{
    Microwave microwave_1;
    RemoteControl rc_1 = RemoteControl(microwave_1);
    rc_1.set_time(33, 5);
    rc_1.del_time_sec(30);
    rc_1.del_time_min(2);
    rc_1.show_time();
    Microwave microwave_2;
    RemoteControl rc_7 = RemoteControl(microwave_2);
    rc_7.set_time(0, 15);
    rc_7.add_time_sec(90);
    rc_7.add_time_min(12);
    rc_7.show_time();
    Microwave microwave_3;
    RemoteControl rc_8 = RemoteControl(microwave_3);
    rc_8.add_time_sec(10);
    rc_8.add_time_sec(15);
    rc_8.add_time_min(12);
    rc_8.show_time();
    Microwave microwave_4;
    RemoteControl rc_6 = RemoteControl(microwave_4);
    rc_6.set_time(20,9);
    rc_6.del_time_sec(35);
    rc_6.add_time_sec(40);
    rc_6.show_time();
return 0; 
}
