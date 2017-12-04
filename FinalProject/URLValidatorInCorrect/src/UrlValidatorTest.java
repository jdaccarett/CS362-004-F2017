/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   /*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   //First, just do manual testing. Call the valid method of URLValidator with different possible
   //valid/invalid inputs and see if you find a failure

   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Valid URL Examples
	   //Source Cite: http://formvalidation.io/validators/uri/
	   System.out.println(" \n********** Manual Testing (Valid should all pass **********\n");                      
	 
	   System.out.println(urlVal.isValid("http://foo.com/blah_blah"));                          //true
	   System.out.println(urlVal.isValid("http://foo.com/blah_blah_(wikipedia)"));              //true
	   System.out.println(urlVal.isValid("http://142.42.1.1/"));                                //true
	   System.out.println(urlVal.isValid("https://www.example.com/foo/?bar=baz&inga=42&quux")); //true
 	   System.out.println(urlVal.isValid("https://www.example.com/foo/bar=baz&inga=42&quux"));  //true
	   System.out.println(urlVal.isValid("https://www.example.com/foo/"));                      //true
	   System.out.println(urlVal.isValid("https://www.example.com/foo/?")); 					  //true
	   System.out.println(urlVal.isValid("https://www.example.com:8080/foo/")); 				  //true
	   System.out.println(urlVal.isValid("http://142.42.1.1:8080/"));							  //true
	   System.out.println(urlVal.isValid("http://142.42.1.1"));								  //true

	   System.out.println("\n********** Manual Testing (Invalid should all fail **********\n");                      
	   
	   //InValid URL Examples
	   System.out.println(urlVal.isValid("http://."));                                    //false
	   System.out.println(urlVal.isValid("http://foo.bar?q=Spaces should be encoded"));   //false
	   System.out.println(urlVal.isValid("foo.com"));                                     //false
	   System.out.println(urlVal.isValid(":// should fail"));        				        //false
	   System.out.println(urlVal.isValid("http://10.1.1.254"));                			//false
   }
   
   //Testing Urls With ports (bug noticed in manual testing).
   ResultPair[] UrlWithPort = {
		   new ResultPair("https://www.example.com:80\"", true),
           new ResultPair("https://www.example.com:65535", true),
           new ResultPair("", true),
           new ResultPair("ftp://www.hey", true),
           new ResultPair("https://www.example.com:-1", false),
           new ResultPair("https://www.example.com:65636", true),
           new ResultPair("https://www.example.com:65a", false)
   };
   
   // Testing UrlsQuery (bug noticed in manual testing error when using "?").
   ResultPair[] testUrlQuery = {
		   new ResultPair("https://www.example.com/foo/?action=view", true),
           new ResultPair("https://www.example.com/foo/?action=edit&mode=up", true),
           new ResultPair("", true),
           new ResultPair("https://www.example.com/foo/action=view", true),
           new ResultPair("https://www.example.com/foo/?param=valid&param2=valid", true),
           new ResultPair("https://www.example.com/foo/?", true),
           new ResultPair("https://www.example.com/foo/?param=valid&&", false),
           new ResultPair("https://www.example.com/foo/?param=valid?param=valid", false),
   };
   
   
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("\n********** First Partion Testing Start **********");               
	   
	   for( int i = 0; i < UrlWithPort.length; i++)
	   {
		   System.out.println(urlVal.isValid(UrlWithPort[i].item));               
	   }
   }
   
   public void testYourSecondPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   System.out.println("\n********** Second Partion Testing Start **********\n");               

	   for( int i = 0; i < testUrlQuery.length; i++)
	   {
		   System.out.println(urlVal.isValid(testUrlQuery[i].item));               
	   }
   }
   
   
public void testIsValid()
{
	   	
	     // Generates random distinct port numbers ranging from 0 - 10000
	     // next it attaches the number to a valid url and checks if its valid 
	     // with the port number attached
	     UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	     final Random r = new Random();
	     final Set<Integer> s = new HashSet<>();
	     for(int i = 0; i < 10000; i++){
	    	 		while(true) {
	               int num = r.nextInt(10000) + 1;
	               if (s.contains(num) == false) {
	                   s.add(num);
	                   // Append random port number to valid url and check its validity
	                   // If the url is valid print the url and see which port numbers are currently valid.
	                   // This will allows to catch on patterns. For example the current unit tests shows
	                   // that all valid port numbers from 0 - 10000 tests only port numbers with 3 digits or
	                   // less are being marked as valid. This seems like a potential bug.
	                   StringBuilder sb = new StringBuilder (String.valueOf ("https://www.example.com:"));
	                   sb.append (num);
	                   String newStr = sb.toString ();
	        		      System.out.println(urlVal.isValid(newStr));               
	        		      if(urlVal.isValid(newStr)) {
		        		      System.out.println(newStr);
	        		      }
	                   break;
	               }
	           }
	     }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
