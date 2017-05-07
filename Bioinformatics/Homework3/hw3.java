import java.io.*;
import java.util.*;

// compilation: javac -Xlint hw3.java
// running: java hw3 first.pdb second.pdb

public class hw3
{
	public static void main(String[] argv) throws FileNotFoundException, IOException
	{
		String pdbFile1 = null;
		String pdbFile2 = null;

		if (argv.length!=2)
		{
			System.err.println("Usage: java hw3 <pdb file 1> <pdb file 2>");
			System.exit(1);
		}
		else
		{
			pdbFile1 = argv[0];
			pdbFile2 = argv[1];
		}

		BufferedReader pdbReader1 = new BufferedReader(new FileReader(pdbFile1));
		BufferedReader pdbReader2 = new BufferedReader(new FileReader(pdbFile2));

		String pdbLine = pdbReader1.readLine();
		
		Vector coords1 = new Vector(0,1);

		while (pdbLine!=null)
		{
			if (pdbLine.startsWith("ATOM"))
			{
				if (pdbLine.substring(13,15).equals("CA"))
				{
					double x = new Double(pdbLine.substring(31,38)).doubleValue();
					double y = new Double(pdbLine.substring(39,46)).doubleValue();
					double z = new Double(pdbLine.substring(47,54)).doubleValue();
					coords1.addElement(new Coordinate(x,y,z));
				}
			}
			pdbLine = pdbReader1.readLine();
		}

		pdbReader1.close();

		Vector coords2 = new Vector(0,1);
		
		pdbLine = pdbReader2.readLine();

		while (pdbLine!=null)
		{
			if (pdbLine.startsWith("ATOM"))
			{
				if (pdbLine.substring(13,15).equals("CA"))
				{
					double x = new Double(pdbLine.substring(31,38)).doubleValue();
					double y = new Double(pdbLine.substring(39,46)).doubleValue();
					double z = new Double(pdbLine.substring(47,54)).doubleValue();
					coords2.addElement(new Coordinate(x,y,z));
				}
			}
			pdbLine = pdbReader2.readLine();
		}

		pdbReader2.close();

		double[][] prot1coords = new double[coords1.size()][3];
		double[][] prot2coords = new double[coords2.size()][3];

		for (int i=0;i<coords1.size();i++)
		{
			prot1coords[i][0] = ((Coordinate)coords1.elementAt(i)).x;
			prot1coords[i][1] = ((Coordinate)coords1.elementAt(i)).y;
			prot1coords[i][2] = ((Coordinate)coords1.elementAt(i)).z;
		}

		for (int i=0;i<coords2.size();i++)
		{
			prot2coords[i][0] = ((Coordinate)coords2.elementAt(i)).x;
			prot2coords[i][1] = ((Coordinate)coords2.elementAt(i)).y;
			prot2coords[i][2] = ((Coordinate)coords2.elementAt(i)).z;
		}

        double[][] prot1distance = new double[coords1.size()][coords1.size()];
		double[][] prot2distance = new double[coords2.size()][coords2.size()];

		prot1distance = distanceMatrix(coords1);
		prot2distance = distanceMatrix(coords2);

		double minDist = Double.POSITIVE_INFINITY;
        double rmsd = 0;
		int minS1 = 0;
		int minS2 = 0;

        for(int s1=0; s1<coords1.size()-20; s1++)
        {
            for(int s2=0; s2<coords2.size()-20; s2++)
            {
                for (int x=0; x<20; x++)
                {
                    rmsd = localSuperImpose(s1, s2, x, rmsd, prot1distance, prot2distance);
                }

                if (minDistChecker(minDist, rmsd))
                {
                    minDist = rmsd;
                    minS1 = minCoordinate(s1, s2)[0];
                    minS2 = minCoordinate(s1, s2)[1];
                }
                rmsd = 0;
            }
        }
        System.out.println("Seed Alignment found at\n" + "======================");
		System.out.println("Prot1: " + pdbFile1.substring(0, pdbFile1.length()-4) + " " + minS1);
		System.out.println("Prot2: " + pdbFile2.substring(0, pdbFile1.length()-4) + " " + minS2);
    }

    public static double localSuperImpose(int s1, int s2, int x, double rmsd, double[][] prot1distance, double[][] prot2distance)
    {
    	for (int i=0; i<20; i++)
	    {
	    	double absolute = prot1distance[s1+x][s1+i] - prot2distance[s2+x][s2+i];
	    	if(absolute < 0) absolute = -1 * absolute;
	        rmsd = rmsd + absolute;
	    }
	    return rmsd;
    }

    public static boolean minDistChecker(double minDist, double rmsd)
    {
    	if(rmsd < minDist)
    	{
    		return true;
    	}
    	return false;
    }

    public static int[] minCoordinate(int s1, int s2) {
    	int[] coords = new int[2];
    	coords[0] = s1 + 1;
    	coords[1] = s2 + 1;
    	return coords;
    }

    public static double[][] distanceMatrix(Vector coords)
    {
    	double[][] protDistances = new double[coords.size()][coords.size()];
    	for (int i=0;i<coords.size();i++)
        {
            for (int j=0;j<coords.size();j++)
            {
            	double diffX = ((Coordinate)coords.elementAt(i)).x-((Coordinate)coords.elementAt(j)).x;
            	double diffY = ((Coordinate)coords.elementAt(i)).y-((Coordinate)coords.elementAt(j)).y;
            	double diffZ = ((Coordinate)coords.elementAt(i)).z-((Coordinate)coords.elementAt(j)).z;
            	protDistances[i][j] = Math.sqrt(Math.pow(diffX,2) + Math.pow(diffY,2) + Math.pow(diffZ,2));
            }
        }
        return protDistances;
    }
}

class Coordinate
{
	public double x,y,z;

	public Coordinate(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}
}