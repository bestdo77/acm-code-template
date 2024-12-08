所以在通常的场合下，0x3f3f3f3f真的是一个非常棒的选择。
 
其他常用赋值：
 
memset(arr,0x7F,sizeof(arr)); //它将arr中的值全部赋为2139062143，这是用memset对int赋值所能达到的最大值
 
memset(arr,0x80,sizeof(arr)); //set int to -2139062144 //赋负值
 
给double赋值：
memset(arr,0x7F,sizeof(arr)); //set double to 1.38242e+306
memset(arr,0xFE,sizeof(arr)); //set double to -5.31401e+303