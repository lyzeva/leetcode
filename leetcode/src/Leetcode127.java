/**
 * Created by evaliu on 16-8-24.
 */
import java.util.*;

public class Leetcode127 {

    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {

        int wordLength = beginWord.length();
        int size = Math.pow(26,wordLength);
        boolean wordSet[] = new boolean[size](true);
        for(String str: wordList){
            wordSet[str2int(str)] = true;
        }

        Queue<Integer> queue = new Queue<Integer>();
        int endValue = str2int(endWord);
        queue.add(str2int(beginWord));
        int step = 1;
        while(queue.peek() != null){
            int value = queue.poll();
            for(int i=0; i<wordLength; i++){
                int base = (int)(Math.pow(26,i));
                int positionValue = value/base%26;
                for(int j=0; j<26; j++)
                    if(j != positionValue){
                        int changedValue = value + (j-positionValue)*base;
                        if(changedValue == endValue){
                            return step+1;
                        }
                        if(wordSet[changedValue]){
                            wordSet[changedValue] = false;
                            queue.add(changedValue);
                        }
                    }
            }
            step++;
        }
        return 0;
    }

    private int str2int(String str, int wordLength){
        int value = 0;
        for(int i=0; i<wordLength; i++){
            value *= 26;
            value += (str[i]-'a');
        }
        return value;
    }

}
