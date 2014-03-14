import java.util.*;
import java.math.*;
public class Main
{
	 public static void main(String[] args)
	 {
		BigInteger[] all=new BigInteger[110];
		BigInteger one=new BigInteger("1");
		BigInteger zero=new BigInteger("0");
		all[0]=one;
		all[1]=one;
		int i;
		for(i=2;i<=100;i++)
		{
			all[i]=zero;
			int j;
			for(j=0;j<=i-1;j++)
			{
				all[i]=all[i].add(all[j].multiply(all[i-1-j]));
			}
		}
		Scanner input = new Scanner(System.in);
		while(input.hasNext())
		{
			int n=input.nextInt();
			if(n==-1) break;
			 System.out.println(all[n]);
		}
	 }
}