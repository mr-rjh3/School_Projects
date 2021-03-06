package CP312;

import java.util.*;

public class Index {
/*
three-A three-A 2 0 0 1 3 1 7 3 0 0 1 0 2 1 1 3 1 
five-A five-A 1 5 2 4 13 2 7 7 2 2 2 2 6 2 4 4 3 
one-A one-A 0 2 0 0 0 1 1 1 1 0 0 0 1 0 0 0 0 
six-A six-A 7 8 10 1 1 3 3 1 1 2 6 6 2 3 2 7 4 
seven-A seven-A 11 1 13 1 7 4 3 4 15 9 2 3 4 9 3 12 1 
two-A two-A 0 1 1 1 0 1 0 1 2 1 1 4 1 2 1 0 1 
thirteen-A thirteen-A 8 15 35 4 17 14 15 18 1 14 31 18 13 27 13 32 6 
thirteen-B thirteen-B 13 19 24 17 14 17 14 5 13 16 7 20 13 36 5 18 17 
*/
	
	static public int ResearchRank(ArrayList<Integer> c, int Start, int End , int hindex) {
		if(Start >= End) {
			if(c.get(Start) >= Start + 1)
				hindex = Start + 1;
			return hindex;
		}
		int mid = ((Start + End) / 2);
		int i = c.get(mid);
		if(i > mid + 1) { // Right
			hindex = mid + 1;
			return ResearchRank(c, mid + 1, End, hindex);
		}
		else if(i < mid + 1) // Left
			return ResearchRank(c, Start, mid - 1, hindex);
		else
			return mid + 1;
	}
	
	
	public static void main(String[] args) {
		ArrayList<String> researchers = new ArrayList<String>();
		ArrayList<String[]> researcherSort = new ArrayList<String[]>();
		int hindex = 0;
		
		
        Scanner in = new Scanner(System.in);
        String input = null;
        while (!(input = in.nextLine()).isEmpty())
        {
            researchers.add(input);
        }
        in.close();
		
        researchers.sort(Comparator.reverseOrder());
        
        for (String str : researchers) 
        {
        	ArrayList<Integer> c = new ArrayList<Integer>();
        	int rank = 0;

        	String[] researcher = str.split(" ");
            
            for(int i = 2; i < researcher.length; i++) {
            	c.add(Integer.parseInt(researcher[i]));
            }
            c.sort(Comparator.reverseOrder());
            rank = ResearchRank(c, 0, c.size()-1, hindex);
    		researcherSort.add(new String[] {researcher[0], researcher[1], String.valueOf(rank)});
        }

		researcherSort.sort(Comparator.comparingInt(el -> Integer.parseInt(el[2])));
		
		Collections.reverse(researcherSort);
		
		for (String[] str : researcherSort) {
			System.out.println(str[0] + " " + str[1] + " : " + str[2]);
		}
	}
}