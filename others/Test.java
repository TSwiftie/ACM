import java.util.HashMap;
import java.util.Stack;
public class Test{
    public boolean judge(String s){
        Stack<Character> S = new Stack<>();
        for(int i = 0;i < s.length();++i){
            char now = s.charAt(i);
            if(S.empty()||now=='{'||now=='['||now=='(') S.push(now);
            else if((S.peek()=='{'&&now=='}')||(S.peek()=='['&&now==']')||(S.peek()=='('&&now==')')) S.pop();
            else S.push(now);
        }
        return S.empty();
    }
    public static void main(String []argv){
        Test t = new Test();
        System.out.println(t.judge("{[}]"));
    }
}
