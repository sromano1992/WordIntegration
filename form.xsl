<?xml version="1.0"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head>
    <title>Applicazione WEB</title>
    <link rel="stylesheet" href="//netdna.bootstrapcdn.com/bootstrap/3.1.1/css/bootstrap.min.css"/>
    <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.6.2/jquery.min.js"></script>
    <script type="text/javascript">
        function mostraDivScorrevole(){
            $("#divScorrevole").animate({"height": "toggle"}, { duration: 1000 });
        }
    </script>
    <script type="text/javascript">
	function cambiaCheckbox(elemento) {
	    if($(elemento).attr('id') == "italiano") {
                $('#div_inglese').hide();
                $('#div_italiano').show();
        }
        else if($(elemento).attr('id') == "inglese") {
                $('#div_italiano').hide();
                $('#div_inglese').show();
        }
    }
    <!-- function soloNumeri(vnt)
{ var tasto, carattereTasto;
if (window.vnt) //Modello ad eventi IE
tasto = window.vnt.keyCode;
else if (vnt) //Modello ad eventi NN
tasto = vnt.which;
else return true;
//converte Da CharCode (Unicode) a Char
carattereTasto = String.fromCharCode(tasto);
if ((tasto==null) || (tasto==0) || (tasto==8) ||
(tasto==9) || (tasto==13) || (tasto==27) )
return true;
else if ((("0123456789").indexOf(carattereTasto) > -1))
{
window.status = ""; return true;
}
else
{
window.status = "Il campo accetta solo numeri";
return false; }
}
-->
    </script>
        
</head>

<body>
    <div class="jumbotron">
        <h1>LPR Application</h1>
        <!-- <p><a class="btn btn-primary btn-lg" href="#autori" role="button">Learn more about the authors</a></p> -->
    </div>
    <section style="position:relative">
	<div style="width: 800px;height: 400px;position:relative;top:0;left:20%;display:inline-block;">
	    <form role="form" action="generateOutput.php" method="post">
		<div class="form-group">
		    <label for="parola"><h3>Parola/Word:</h3></label>
		    <input type="text" class="form-control" id="parola" name="parola" placeholder="Inserisci la parola/Insert the word..." onclick="soloNumeri(this)" required="true"/>
		</div>
		<br/>
		<div style="margin-left: 330px">
		    <label class="radio-inline">
			<input type="radio" name="lingua" id="italiano" value="italiano" required="true" checked="true" onclick="cambiaCheckbox(this);"/>Italiano
	            </label>
	            <label class="radio-inline">
	                <input type="radio" name="lingua" id="inglese" value="inglese" onclick="cambiaCheckbox(this);"/>Inglese
	            </label>
	        </div>
		<br />
		<div id="div_italiano" style="text-align:center;">
		    <label class="checkbox-inline">
			<input type="checkbox" id="sinonimi" value="sinonimi" name="checkbox[]"/> Sinonimi
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="contrari" value="contrari" name="checkbox[]"/> Contrari
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="rime" value="rime" name="checkbox[]"/> Rime
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="contesti" value="contesti" name="checkbox[]"/> Contesti
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="wikipedia" value="wikipedia" name="checkbox[]"/> Wikipedia
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="dialetti" value="dialetti" name="checkbox[]"/> Dialetti
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="taduzioni" value="traduzioni" name="checkbox[]"/> Traduzione
		    </label>
		    <label class="checkbox-inline">
			<input type="checkbox" id="modi" value="modi" name="checkbox[]"/> Modi di dire
		    </label>
		</div>
		<div id="div_inglese" style="display: none; text-align:center;">
		    <label class="checkbox-inline">
			<input type="checkbox" id="wikipedia" value="wikipedia" name="checkbox[]"/> Wikipedia
		    </label>
		    <label class="checkbox-inline">
		    	<input type="checkbox" id="taduzioni" value="traduzioni" name="checkbox[]"/> Traduzione
		    </label>
		    <label class="checkbox-inline">
		        <input type="checkbox" id="overviews" value="overviews" name="checkbox[]"/> Overviews
		    </label>
		    <label class="checkbox-inline">
		        <input type="checkbox" id="synonyms" value="synonyms" name="checkbox[]"/> Synonyms
		    </label>
		</div>
		<br />
		<button type="submit" class="btn btn-primary" id="invia" name="invia" style="display: block;margin: auto">Invia</button>
	    </form>
	</div>
    </section>
    <section style="position:relative;top:-50px;left:7%;width:88%;">
	<xsl:apply-templates select="//sinonimi" />
	<xsl:apply-templates select="//contrari" />
	<xsl:apply-templates select="//rime" />	
	<xsl:apply-templates select="//contesti" />
	<xsl:apply-templates select="//dialetti" />
	<xsl:apply-templates select="//traduzioni" />    
	<xsl:apply-templates select="//overview" />
	<xsl:apply-templates select="//synsn" />
	<xsl:apply-templates select="//modi_di_dire" />
	<xsl:apply-templates select="//wiki" />
	 
    </section>
    <footer>
        <div id="div_footer" style="position:fixed;z-index:20">
            <nav class="navbar navbar-default navbar-fixed-bottom" role="navigation">
                <div class="col-md-4"></div>
                <div class="col-md-6" id="div_footer_1">
                    <div class="container">
                        <div class="row">
                            <ul class="nav nav-pills">
                                <li>Amedeo Leo<a href="#" style="display: inline-block"><img src="linkedin.png" /></a></li>
                                <li>Alessio Petrozziello<a href="#" style="display: inline-block"><img src="linkedin.png" /></a></li>
                                <li>Simone Romano<a href="#" style="display: inline-block"><img src="linkedin.png" /></a></li>
                            </ul>
                        </div>
                    </div>
                </div>
            </nav>
        </div>
    </footer>
</body>
</html>
</xsl:template>

<xsl:template match="sinonimi">
    <xsl:choose>
        <xsl:when test="sinonimo">
	    <div style="float:left; display:block;width:100%" class="panel panel-info">
	        <div class="panel-heading"><h4>Sinonimi</h4></div>
		<ul class="list-inline" style="margin-left:3px">
		    <xsl:for-each select="sinonimo">
			<li class="list-group-item">
			    <xsl:value-of select="."/>
			</li>
		    </xsl:for-each>
		</ul>
	    </div>
	</xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
		<div class="panel-heading"><h4>Sinonimi</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="contrari">
    <xsl:choose>
  	<xsl:when test="contrario">
	    <div style="float:left; display:block;width:100%" class="panel panel-info">
	        <div class="panel-heading"><h4>Contrari</h4></div>
	        <ul class="list-inline" style="margin-left:3px">
		    <xsl:for-each select=".">
		        <li class="list-group-item">
			    <xsl:value-of select="."/>
		        </li>
		    </xsl:for-each>
	        </ul>
	    </div>
	</xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
	        <div class="panel-heading"><h4>Contrari</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="rime">
    <xsl:choose>
  	<xsl:when test="rima">
	    <div style="float:left; display:block;width:100%" class="panel panel-info">
	        <div class="panel-heading"><h4>Rime</h4></div>
	        <ul class="list-inline" style="margin-left:3px">
		    <xsl:for-each select="rima">
			<li class="list-group-item">
			    <xsl:value-of select="."/>
			</li>
		    </xsl:for-each>
		</ul>
	    </div>
	</xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
	        <div class="panel-heading"><h4>Rime</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="contesti">
    <xsl:choose>
        <xsl:when test="contesto">
	    <div style="float:left; display:block;width:100%" class="panel panel-info">
	        <div class="panel-heading"><h4>Contesti</h4></div>
	        <ul class="list-inline" style="margin-left:3px">
		    <xsl:for-each select=".">
      			<li class="list-group-item">
			    <xsl:value-of select="."/> 
        		</li>
		    </xsl:for-each>
		</ul>
	    </div>		
	</xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
	        <div class="panel-heading"><h4>Contesti</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="dialetti">
    <div style="float:left; display:block;width:100%" class="panel panel-info">
	<div class="panel-heading"><h4>Dialetti</h4></div>
        <table class="table table-striped" style="position:relative;width:50%;left:25%">
            <tr style="text-align:center">
                <th style="text-align:center">Dialetto</th>
	        <th style="text-align:center">Regione</th>
	    </tr>
	    <xsl:for-each select="dialetto">
	        <tr>
		    <td style="text-align:center"> <xsl:value-of select="voce"/> </td> 
		    <td style="text-align:center"> <xsl:value-of select="localita"/> </td>
	        </tr>
	    </xsl:for-each>
	</table>
    </div>
</xsl:template>

<xsl:template match="traduzioni">
    <div style="float:left; display:block;width:100%" class="panel panel-info">
	<div class="panel-heading"><h4>Traduzioni</h4></div>
	<ul class="list-group">
	    <xsl:for-each select="traduzione">
		<li class="list-group-item">
		    <xsl:value-of select="."/> (da <xsl:value-of select="./@da"/> a <xsl:value-of select="./@a"/>) 
		</li>
	    </xsl:for-each>
	</ul>
    </div>
</xsl:template>

<xsl:template match="modi_di_dire">
    <xsl:choose>
  	<xsl:when test="modo_di_dire">
	    <div style="float:left; display:block;width:100%" class="panel panel-info">
	    <div class="panel-heading"><h4>Modi di dire</h4></div>
		<ul class="list-inline" style="margin-left:3px">
		    <xsl:for-each select="modo_di_dire">
		        <li class="list-group-item">
			    <xsl:value-of select="."/>
			</li>
		    </xsl:for-each>
    		</ul>
	    </div>
	</xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
	        <div class="panel-heading"><h4>Modi di dire</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="wiki">
    <xsl:choose>
  	<xsl:when test="line">
	    <div style="float:left; display:block;width:100%" class="panel panel-info">
		<div class="panel-heading"><h4>Wikipedia</h4></div>
    		<ul class="list-inline" style="margin-left:3px">
		    <xsl:for-each select="line">
			<xsl:value-of select="."/><br/>
		    </xsl:for-each>
		</ul>
	    </div>
	 </xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
	        <div class="panel-heading"><h4>Wikipedia</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="overview">
	<xsl:choose>
        <xsl:when test="line">
    <div style="float:left; display:block;width:100%" class="panel panel-info">
	<div class="panel-heading"><h4>Overview</h4></div>
	<ul>
	    <xsl:for-each select="line">
		<li style="list-style:none">
		    <xsl:value-of select="."/>
		</li>
	    </xsl:for-each>
    	</ul>
    </div>
    </xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
		<div class="panel-heading"><h4>Overview</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

<xsl:template match="synsn">
	<xsl:choose>
        <xsl:when test="line">
    <div style="float:left; display:block;width:100%" class="panel panel-info">
	<div class="panel-heading"><h4>Synonyms</h4></div>
    	<ul>
	    <xsl:for-each select="line">
		<li style="list-style:none">
		    <xsl:value-of select="."/>
		</li>
	    </xsl:for-each>
	</ul>
    </div>
    </xsl:when>
	<xsl:otherwise>
	    <div style="float:left; display:block;width:100%" class="panel panel-danger">
		<div class="panel-heading"><h4>Synonyms</h4></div>
	    </div>
	</xsl:otherwise>
    </xsl:choose>
</xsl:template>

</xsl:stylesheet>