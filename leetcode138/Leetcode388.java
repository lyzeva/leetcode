import java.util.ArrayList;

/**
 * Created by anwenqiao on 2016/9/1.
 */
public class Solution {

    public int lengthLongestPath(String input) {
        String[] path = input.split("\n");
        int[] length = new int[path.length];
        int max = 0;
        for(String c:path){
            String name = c.replace("\t","");
            int pos = c.length()-name.length();
            if(pos>0)
                length[pos] = length[pos-1]+name.length()+1;
            else
                length[pos] = name.length();
            if(c.indexOf(".") != -1 && length[pos] > max)
                max = length[pos];
        }
        return max;
    }

}