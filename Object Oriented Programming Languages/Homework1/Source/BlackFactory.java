public class BlackFactory extends TokenFactory {

	public BlackFactory() {
    }

	@Override
	public Token createToken(int xLower, int xUpper, int yLower, int yUpper) {
		Vector2D tempVect = Vector2D.randomVector(xLower, xUpper, yLower, yUpper);
		return new Black(tempVect.x, tempVect.y);
	}
}