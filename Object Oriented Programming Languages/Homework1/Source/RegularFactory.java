public class RegularFactory extends TokenFactory {

    public RegularFactory() {
    }

    @Override
	public Token createToken(int xLower, int xUpper, int yLower, int yUpper) {
		Vector2D tempVect = Vector2D.randomVector(xLower, xUpper, yLower, yUpper);
		return new Regular(tempVect.x, tempVect.y);
	}
}