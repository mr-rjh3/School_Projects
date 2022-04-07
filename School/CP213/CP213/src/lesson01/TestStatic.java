package lesson01;


//------------------------------------QUIZ 01------------------------------------
public class TestStatic {

	public static void test() {
	     long l = 55;
	     int i = 44;
	     short s = 33;
	     byte b = 22;

	     i = (int) l;
	     s = (short) i;
	     b = (byte) s;

	     System.out.println("l = " + l);
	     System.out.println("i = " + i);
	     System.out.println("s = " + s);
	     System.out.println("b = " + b);
	}
	
//	public static void test2()
//	{
//	     int i = 50000;
//	     short s = i;
//	}
//	
	public static void test3() {
	     int input = 7;
	     int output = ++input + ++input + ++input;
	     System.out.println(output);
	}
	public static void test4() {
	     int i = 4;
	     int j = 21;

	     int k = ++i * 7 + 2 - j--;
	     System.out.println("k = " + k);
	     System.out.println("i = " + i);
	     System.out.println("j = " + j);

	}
	public static void test5() {

	     int a = 1;
	     int b = 2;
	     int c;
	     int d;

	     c = ++b;
	     d = a++;

	     c++;

	     System.out.println("a = " + a);
	     System.out.print("b = " + b);
	     System.out.println("c = " + c);
	     System.out.print("d = " + d);
	}
	
    int num1 = 6;
    static int num2 = 10;

    public static void main(String args[]) {
         TestStatic s1 = new TestStatic();
         TestStatic s2 = new TestStatic();
         s1.num1 = 15;
         s1.num2 = 17;
         s2.num1 = 22;
         s2.num2 = 28;
         System.out.println(s1.num1 + " " + s1.num2 + " " + s2.num1 + " " + s2.num2);
    }
}
