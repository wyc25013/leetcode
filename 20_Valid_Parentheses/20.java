public class Solution {
    public boolean isValid(String s) {
        int len = s.length();
        if(len==0) return true;
        Stack<Character> inner = new Stack<Character>();
        for(int i = 0; i<len;i++){
            char cai = s.charAt(i);
            if(cai=='('||cai=='['||cai=='{')
                inner.push(cai);
            else{
                if(cai==')'){
                    if(inner.empty()==false&&inner.peek()=='(')
                        inner.pop();
                    else return false;
                }else if(cai==']'){
                    if(inner.empty()==false&&inner.peek()=='[')
                        inner.pop();
                    else return false;
                }else{
                    if(inner.empty()==false&&inner.peek()=='{')
                        inner.pop();
                    else return false;
                }
            }
        }
        return inner.empty();
    }
}