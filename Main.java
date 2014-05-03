import java.io.*;
import java.util.*;
import java.math.*;

public class Main{

public static void main(String arg[])
	{
	ArrayList<BigInteger> ar = new ArrayList<BigInteger>();

	Scanner scan = new Scanner(System.in);

	BigInteger a = new BigInteger("1");
	BigInteger b = new BigInteger("2");
	BigInteger c = new BigInteger("3");

	ar.add(a);
	ar.add(b);

	int i,j,k;

	for(i=0;i<=150;i++)
		{
		c=a.add(b);
		ar.add(c);
		a=b;
		b=c;
		}

	String s1,s2;

	boolean flg=false,EOF=false;

	while(scan.hasNext())
		{
		s1 = scan.next();
		s2 = scan.next();

		if(flg)
			System.out.println();
		flg=true;

		int len1 = s1.length();
		int len2 = s2.length();

		BigInteger x = new BigInteger("0");
		BigInteger y = new BigInteger("0");
		BigInteger z = new BigInteger("0");

		//BigInteger x = scan.nextBigInteger();
		//BigInteger y = scan.nextBigInteger();

		Queue<String> q = new LinkedList<String>();

		int coun=0;

		for(i=len1-1;i>=0;i--)
			{
			if(s1.charAt(i)=='1')
				{
				z=ar.get(coun);
				x=x.add(z);
				}
			coun++;
			}

		coun=0;

		for(i=len2-1;i>=0;i--)
			{
			if(s2.charAt(i)=='1')
				{
				z=ar.get(coun);
				y=y.add(z);
				}
			coun++;
			}

		x=x.add(y);

		int pos=0;

		for(i=0;i<=100;i++)
			if(((ar.get(i)).compareTo(x))==1)
				{
				pos=i-1;
				break;
				}
		if(pos<0)
			System.out.println("0");
		else{
		BigInteger zer = new BigInteger("0");
		/*z=x;
		while(true)
			{
			if(z.compareTo(zer)==0)
				break;
			while(!q.isEmpty())
				q.remove();*/
			z=x;
			for(i=pos;i>=0;i--)
				{
				if(((z.compareTo(ar.get(i)))==1||(z.compareTo(ar.get(i))==0))&&(z.compareTo(zer))!=0)
					{
					z=z.subtract(ar.get(i));
					q.add("1");
					}
				else
					q.add("0");
				}
			/*pos--;
			}*/
		while(!q.isEmpty())
			System.out.print(q.poll());
		System.out.println();
		}
	}
}
}