//***************************************************************************************************************************************************

import java.util.List ;

//***************************************************************************************************************************************************




//***************************************************************************************************************************************************

public class Reply
{
  //=================================================================================================================================================

  private final String         description ;  // "Index", "Document" or "404"
  private final List< String > content     ;

  //=================================================================================================================================================

  public Reply ( String description , List< String > content )
  {
    this.description = description ;
    this.content     = content     ;
  }

  //=================================================================================================================================================

  @Override public String toString ()
  {
    // TODO
      String result = "[" + description + ":";
      for(String cont : content) {
          result += cont + ",";
      }
      result = result.substring(0, result.length()-1);
      result += "]";
      return result;
  }

  //=================================================================================================================================================
}

//***************************************************************************************************************************************************
