/**************************************************************
BlackBug Engineering
30.11.2022
https://github.com/dbprof/me-arm
УСТАНОВКА СЕРВОПРИВОДОВ В НАЧАЛЬНОЕ ПОЛОЖЕНИЕ ДЛЯ СБОРКИ
***************************************************************/
int servopin5=5;    //нижний сервопривод  - управление вправо/влево
int servopin9=9;    //правый сервопривод  - управление вверх/вниз
int servopin10=10;  //левый сервопривод   - управление дальше/ближе
int servopin11=11;  //верхний сервопривод - управление клешней
int myangle;        //угол поворота
int pulsewidth;     //длительность импульса
void setup()
{
  pinMode(servopin5,OUTPUT);  //настройка пинов сервоприводов для вывода
  pinMode(servopin9,OUTPUT);  
  pinMode(servopin10,OUTPUT); 
  pinMode(servopin11,OUTPUT); 
} 
void servopulse(int servopin,int myangle)
{
  pulsewidth=(myangle*11)+500;    //преобразование угла поворота в длительность импульса
  digitalWrite(servopin,HIGH);    //включение сервопривода
  delayMicroseconds(pulsewidth);  //задержка для достижения заданного положения
  digitalWrite(servopin,LOW);     //выключение сервопривода
  delay(20-pulsewidth/1000);      //задержка
}
void loop()
{
  servopulse(servopin5,80);       //перемещение серво в начальное положение для сборки
  servopulse(servopin9,150);
  servopulse(servopin10,0);
  servopulse(servopin11,15);
}
