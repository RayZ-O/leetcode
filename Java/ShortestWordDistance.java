// Given a list of words and two words word1 and word2, return the shortest distance between
// these two words in the list.

// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

public class ShortestWordDistance {
   public int shortestDistance(String[] words, String word1, String word2) {
        int pos1 = -1;
        int pos2 = -1;
        int min = words.length;
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1))
                pos1 = i;
            if (words[i].equals(word2))
                pos2 = i;
            if (pos1 != -1 && pos2 != -1)
                min = Math.min(min, Math.abs(pos1 - pos2));
        }
        return min;
    }
}
