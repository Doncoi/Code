import java.math.*;
import java.util.*;
public class Main 
{
	public static void main(String []arg)
	{
		Scanner sc=new Scanner(System.in);
		int t;
		t=sc.nextInt();
		while(t>0)
		{
			t--;
			BigInteger a=new BigInteger(sc.next()),b=new BigInteger(sc.next()),mod=new BigInteger(3+"");
			int ai=a.remainder(mod).intValue(),bi=b.remainder(mod).intValue();
			if(ai==2) 
				ai=1;
			else
				ai=0;
			if(bi==1)
				bi=1;
			else
				bi=0;
			if(ai==1&&bi==1)
				System.out.println("0");
			else if(ai==1||bi==1)
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
