// your code goes here
input1 = 10;
input2 = 1;
input3 = "-1";
input4 = "7";
var output=new Array();
var out="";
var totalOutput = 0;
function checkEq(cards, whites, blacks)
{
	if(whites[0]!=-1)
  {
	for(i = 0 ; i<whites.length  ; ++i)
  {
  	if(cards[whites[i]-1]!=1 )
    {
    	return 0;
    }
  }
  }
  if(blacks[0]!=-1)
 {
  for(i = 0 ; i<blacks.length ; ++i)
  {
  	if(cards[blacks[i]-1]!=0 )
    {
    	return 0;
    }
  }
  }
  return 1; 
}
function joinOutput(cards)
{
	for(i=0;i<cards.length;++i)
  {
  	out =out+cards[i];
  }
}
function flipAll(cards)
{
	newCards = new Array();
  for(j=0;j<cards.length;++j)
  	newCards[j]=cards[j];
  for(j = 0; j< cards.length; ++j)
  {
  	if(cards[j]==1)
    {
    	newCards[j]=0;
      
    }
    else
    	newCards[j]=1;
  }
  return newCards;
}
function flipAllOdd(cards)
{
	newCards = new Array();
  for(j=0;j<cards.length;++j)
  	newCards[j]=cards[j];
  for(j = 1; j< cards.length; j=j+2)
  {
  	if(cards[j]==1)
    {
    	newCards[j]=0;
      
    }
    else
    	newCards[j]=1;
  }
  return newCards;
}
function flipAllEven(cards)
{
	newCards = new Array();
  for(j=0;j<cards.length;++j)
  	newCards[j]=cards[j];
  for(j = 0; j< cards.length; j=j+2)
  {
  	if(cards[j]==1)
    {
    	newCards[j]=0;
      
    }
    else
    	newCards[j]=1;
  }
  return newCards;
}
function flipAllPlusThree(cards)
{
	newCards = new Array();
  for(j=0;j<cards.length;++j)
  	newCards[j]=cards[j];
  for(j = 0; j< cards.length; j=j+3)
  {
  	if(cards[j]==1)
    {
    	newCards[j]=0;
      
    }
    else
    	newCards[j]=1;
  }
  return newCards;
}
function recursiveFlip(cards, chanceLeft, whites, blacks)
{
		
		if(checkEq(cards, whites, blacks))
		{	
    	//alert(1);
      dup=0;
      for(x=0;x<totalOutput;++x)
      {
      	if(output[x]==cards)
        	dup=1;
      }
      if(dup==0)
      {
    	output[totalOutput]= cards;
      totalOutput++;
      }
    	//alert(cards.length);
    	/*if(output.length<2)
      {joinOutput(cards);
      alert(output.length);
      }
      else
      	{
        output= output+"#";
        joinOutput(cards);
        }*/
        
    }
    else
    {
    	if(chanceLeft < 1)
    	return;
    	newCards = flipAll(cards);
      //alert(newCards.length);
      recursiveFlip(newCards, chanceLeft-1, whites, blacks);
      newCards = flipAllOdd(cards);
      recursiveFlip(newCards, chanceLeft-1, whites, blacks);
      newCards = flipAllEven(cards);
      recursiveFlip(newCards, chanceLeft-1, whites, blacks);
      newCards = flipAllPlusThree(cards);
      recursiveFlip(newCards, chanceLeft-1, whites, blacks);
    }
}
function combinationOfCards(input1, input2, input3, input4)
{
	var cards=new Array();
	//alert("as");
	for(i = 0 ; i<input1 ;++i)
	{
		cards[i]=1;
	}
  //alert(cards.length);
	recursiveFlip(cards, input2, input3.split(","),input4.split(",") );
  //alert(output[1].length);
  
  for(p=0;p<totalOutput;p++)
  {
  	if(p>0)
    	out=out+'#';
    joinOutput(output[p]);
    	
  }
  alert(out);
}
combinationOfCards(input1, input2, input3, input4);