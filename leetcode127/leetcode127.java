/**
 * Created by evaliu on 16-8-24.
 */
import java.util.*;

public class Solution {

    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {

        int wordLength = beginWord.length();
//        int size = (int) Math.pow(26,wordLength);
//        boolean[] wordSet = new boolean[size];
//        for(String str: wordList){
//            wordSet[str2int(str, wordLength)] = true;
//        }

        Queue<String> queue = new LinkedList<String>();
//        int endValue = str2int(endWord, wordLength);
        queue.add(beginWord);
        int length = 1;
        while(queue.peek() != null){
            int count = queue.size();
            for(int k = 0; k<count; k++){
                StringBuffer value = new StringBuffer(queue.poll());
                for(int i=0; i<wordLength; i++){
                    char base = value.charAt(i);
//                int positionValue = value/base%26;
                    for(char j='a'; j<='z'; j++)
                        if(j != base){
                            value.setCharAt(i,j);
                            String changedValue = value.toString();
                            if(endWord.equals(changedValue)){
                                return length+1;
                            }
                            if(wordList.contains(changedValue)){
                                wordList.remove(changedValue);
                                queue.add(changedValue);
                            }
                        }
                    value.setCharAt(i,base);
                }
            }
            length++;
        }
        return 0;
    }

    private int str2int(String str, int wordLength){
        int value = 0;
        for(int i=0; i<wordLength; i++){
            value *= 26;
            value += (str.charAt(i)-'a');
        }
        return value;
    }

}
