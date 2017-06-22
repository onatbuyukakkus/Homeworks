public class FakeFactory extends TokenFactory {

    public FakeFactory() {
    }

	@Override
	public Token createToken(int xLower, int xUpper, int yLower, int yUpper) {
		Vector2D tempVect = Vector2D.randomVector(xLower, xUpper, yLower, yUpper);
		return new Fake(tempVect.x, tempVect.y);
	}
}