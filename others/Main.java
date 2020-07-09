import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        Scanner input = new Scanner(System.in);
        System.out.println("请输入需要判断的字符串:");
        String str = input.next();
        boolean ok = true;
        for(int i = 0,j = str.length()-1;i < j;++i,--j)
            if(str.charAt(i)!=str.charAt(j)){
                ok = false;
                break;
            }
        System.out.println(ok?"是回文串":"不是回文串");
        input.close();
    }
}
