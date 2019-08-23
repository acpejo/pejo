#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int t , a , m , v , n , e , o , store = 0 , two , test ;
    long l ;
    
    l = get_long("Number:") ;
    a = (l-l%10000000000000)/10000000000000 ; //15 zero
    m = (l-l%100000000000000)/100000000000000 ;//16 zero
    v = (l-l%1000000000000)/1000000000000 ; //13 zero
    n = (l-l%1000000000000000)/1000000000000000 ; //16 zero
  
    
    if ( (l-l%10000000000000)== 0 )//visa 
    {
        for (int i=0 ; i<13; i++)
        {
            if (i == 0)
            {
                e = l%10 ;
            }
            else if ( i % 2 != 0 )
            {
                long z = 1 ;
                for (int j=0 ; j<i+1 ; j++)
                {
                    z *= 10 ;
                }
                o = (l%z - l%(z/10))/(z/10) ;
                two = 2 * o ;
                if (two>=10)
                {
                    two = (two%100-two%10)/10 + two%10 ; 
                }
                store += two ;
            }  
            else if ( i % 2 == 0 )
            { 
                long z = 1 ;
                for (int j=0 ; j<i+1 ; j++)
                {
                    z *= 10 ;
                }
                e += (l%z - l%(z/10))/(z/10) ;
            }
        }
        test = store + e ;
        if (test%10 == 0 && v == 4)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else if ( (l-l%1000000000000000)== 0 )//amex
    {
        for (int i=0 ; i<15; i++)
        {
            if (i == 0)
            {
                e = l%10 ;
            }
            else if ( i % 2 != 0 )
            {
                long z = 1 ;
                for (int j=0 ; j<i+1 ; j++)
                {
                    z *= 10 ;
                }
                o = (l%z - l%(z/10))/(z/10) ;
                two = 2 * o ;
                if (two>=10)
                {
                    two = (two%100-two%10)/10 + two%10 ; 
                }
                store += two ;
            }  
            else if ( i % 2 == 0 )
            { 
                long z = 1 ;
                for (int j=0 ; j<i+1 ; j++)
                {
                    z *= 10 ;
                }
                e += (l%z - l%(z/10))/(z/10) ;
            }
        }
        test = store + e ;
        if (test%10 == 0 && ( a ==34 || a == 37 ))
        {
            printf("AMEX\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }    
    else if ( (l-l%10000000000000000)== 0 )//master card
    {
        for (int i=0 ; i<16; i++)
        {
            if (i == 0)
            {
                e = l%10 ;
            }
            else if ( i % 2 != 0 )
            {
                long z = 1 ;
                for (int j=0 ; j<i+1 ; j++)
                {
                    z *= 10 ;
                }
                o = (l%z - l%(z/10))/(z/10) ;
                two = 2 * o ;
                if (two>=10)
                {
                    two = (two%100-two%10)/10 + two%10 ; 
                }
                store += two ;
            }  
            else if ( i % 2 == 0 )
            { 
                long z = 1 ;
                for (int j=0 ; j<i+1 ; j++)
                {
                    z *= 10 ;
                }
                e += (l%z - l%(z/10))/(z/10) ;
            }
        }
        test = store + e ;
        if (test%10 == 0 && ( m==51 || m==52 || m==53 || m==54 || m==55 ))
        {
            printf("MASTERCARD\n");
        }
        else if (test%10 == 0 && (n == 4))
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }        
}
