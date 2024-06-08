#define dip1 8
#define dip2 9

#define led1 10
#define led2 11

#define start 12

#define SW 13

int SpeedL = 0 ;
int SpeedR = 0 ;

void motor(int L , int R)
{

    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);

    if (L > 0)
    {
        SpeedL = map(L, 0, 100, 0, 255);
    }
    else 
    {
        SpeedL = map(L, -0, -100, 0, 255);
    }

    if (R > 0)
    {
        SpeedR = map(R, 0, 100, 0, 255);
    }
    else
    {
        SpeedR = map(R, -0, -100, 0, 255);
    }

    analogWrite(5, SpeedL);
    analogWrite(6, SpeedR);

    if (L > 0)
    {
        digitalWrite(2, 1);
        digitalWrite(3, 0);
    }
    else
    {
        digitalWrite(2, 0);
        digitalWrite(3, 1);
    }
    if (R > 0)
    {
        digitalWrite(4, 1);
        digitalWrite(7, 0);
    }
    else
    {
        digitalWrite(4, 0);
        digitalWrite(7, 1);
    }
    if (L == 0)
    {
        analogWrite(5, 255);
        digitalWrite(2, 1);
        digitalWrite(3, 1);
    }
    else if (R == 0)
    {
        analogWrite(6, 255);
        digitalWrite(4, 1);
        digitalWrite(7, 1);
    }
}

void motor_stop()
{
    analogWrite(5, 255);
    analogWrite(6, 255);
    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(7, 1);
}

void wait_SW()
{
    pinMode(SW,INPUT_PULLUP);
    while(!digitalRead(SW)) ;
    while(digitalRead(SW)) ;
}

void led(int led , int status)
{
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);

    if(led == 1 && status == 1)
    {
        digitalWrite(led1,HIGH);
    }
    else if(led == 1 && status == 0)
    {
        digitalWrite(led1,LOW);
    }
    else if(led == 2 && status == 1)
    {
        digitalWrite(led2,HIGH);
    }
    else if(led == 2 && status == 0)
    {
        digitalWrite(led2,LOW);
    }
    else if(led == 12 && status == 1)
    {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
    }
    else if(led == 12 && status == 0)
    {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
    }
    else
    {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
    }
}

int dip(int num)
{
    pinMode(dip1,INPUT_PULLUP);
    pinMode(dip2,INPUT_PULLUP);

    if(num == 1)
    {
        return(digitalRead(dip1));
    }
    else if(num == 2)
    {
        return(digitalRead(dip2));
    }
    else
    {
        return 9999;
    }
}

int readRC(int ch)
{
    if(ch == 0)
    {
        return(pulseIn(A0,HIGH));
    }
    else if(ch == 1)
    {
        return(pulseIn(A1,HIGH));
    }
    else
    {
        return 9999;
    }
}