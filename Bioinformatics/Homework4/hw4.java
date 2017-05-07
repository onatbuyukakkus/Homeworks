import java.util.*;
import java.io.*;

public class hw4
{
	private static String networkFileName = "";

	// The adjacency matrix
	private static Hashtable AdjacencyList = new Hashtable(40000);

	public static int numberOfCores = 1;

	public static ArrayList<String> aList = new ArrayList<String>();
	
	public static void main(String[] argv) throws FileNotFoundException, IOException
	{
			
		// Get command line arguments
		if (argv != null) 
		{
			int len = argv.length;
			if (len == 1) 
			{
				networkFileName = argv[0];
			}
			else printUsage();
		}

		// read the network file and create the adjacency List
	    BufferedReader networkReader = new BufferedReader(new FileReader(networkFileName));

	    String networkLine = networkReader.readLine();
		
		while (networkLine!=null)
		{
			String[] strs = split(networkLine,'\t');
			String p1 = strs[0];
			String p2 = strs[1];

			if (AdjacencyList.containsKey(p1))
			{
				Hashtable n = (Hashtable)(AdjacencyList.get(p1));
				n.put(p2,p2);
			}
			else
			{
				Hashtable n = new Hashtable(20);
				n.put(p2,p2);
				AdjacencyList.put(p1,n);	
			}

			if (AdjacencyList.containsKey(p2))
			{
				Hashtable n = (Hashtable)(AdjacencyList.get(p2));
				n.put(p1,p1);
			}
			else
			{
				Hashtable n = new Hashtable(20);
				n.put(p1,p1);
				AdjacencyList.put(p2,n);	
			}
			
			networkLine = networkReader.readLine();
		}

		Set<String> adjacencyKeys = AdjacencyList.keySet();
		Iterator<String> iterate = adjacencyKeys.iterator();
	 	iter(iterate, adjacencyKeys);
		
		int totalDegree = 0;
		for (Enumeration e=AdjacencyList.keys();e.hasMoreElements();)
		{
			String p = (String)e.nextElement();
			
			Hashtable neighbors = (Hashtable)(AdjacencyList.get(p));
			
			totalDegree+=neighbors.size();
		}
		
	}

	private static void iter(Iterator<String> iterate, Set<String> adjacencyKeys)
	{
		String temp, temp2;
		int doneFlag = 0;
		while(doneFlag != 1)
		{
			aList.clear();
			iterate = remover(iterate, adjacencyKeys);
		    if(AdjacencyList.size() < 1)
		    {
		    	printer();
		    	doneFlag = 1;
		    }
		 	numberOfCores += 1;
		 	adjacencyKeys = AdjacencyList.keySet();
			iterate = adjacencyKeys.iterator();
		}
	}

	private static Iterator<String> remover(Iterator<String> iterate, Set<String> adjacencyKeys)
	{
		String temp, temp2;
		boolean hasNxt = iterate.hasNext();
	    while (hasNxt)
	    { 
	       temp = iterate.next();
	       Hashtable nextHash = ((Hashtable) AdjacencyList.get(temp));
	       if(numberOfCores >= nextHash.size())
	       {
	       		Set<String> adjacencyKeys2 = nextHash.keySet();
				Iterator<String> iterate2 = adjacencyKeys2.iterator();
				boolean hasNxt2 = iterate2.hasNext();
	       		while (hasNxt2)
	       		{
	       			temp2 = iterate2.next();
	       			((Hashtable) AdjacencyList.get(temp2)).remove(temp);
	       			hasNxt2 = iterate2.hasNext();
	       		}
	       		AdjacencyList.remove(temp);       		
	       		aList.add(temp);
	   			adjacencyKeys = AdjacencyList.keySet();
				iterate = adjacencyKeys.iterator();
	       }
	       hasNxt = iterate.hasNext();
	    }
	    return iterate;
	}


	private static void printer()
	{
		Collections.sort(aList);
		String finalString = "The highest k-core is: " + numberOfCores +  " and there are " + aList.size() + " proteins in that " + numberOfCores + "-core. These proteins are: ";
    	for(int i=0;i<aList.size();i++)
    	{
    		finalString += aList.get(i);
    		finalString += " ";
    	}
    	System.out.println(finalString);
	}

	private static void printUsage()
	{
		System.out.println("Usage: java hw4 <network file name>");
		System.exit(1);
	}

	public static String[] split(String str, char delim)
    {
                // begin split
                Vector strsVec = new Vector(0,1);
                String tmp = str;
                while (tmp.indexOf(delim)!=-1)
                {
                		if (tmp.substring(0,tmp.indexOf(delim)).length()>0)
                        	strsVec.addElement(new String(tmp.substring(0,tmp.indexOf(delim))));
                        tmp = tmp.substring(tmp.indexOf(delim)+1,tmp.length());
                }
                strsVec.addElement(new String(tmp));
                String[] strs = new String[strsVec.capacity()];
                for (int s = 0; s < strsVec.capacity(); s++)
                        strs[s] = (String)strsVec.elementAt(s);
                // end of split
                return strs;
    }
}
