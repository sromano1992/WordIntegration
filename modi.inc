<?php

  function modi_di_dire($parola, $FileNameXml){
        shell_exec("curl http://dizionari.corriere.it/dizionario-modi-di-dire/" . ucfirst($parola)[0] . "/" . $parola . ".shtml > scraping.html");
        $string = "curl --data-binary @scraping.html -H \"Content-Type: text/html\"  http://www.it.uc3m.es/jaf/cgi-bin/html2xhtml.cgi > scraping.xhtml";
        shell_exec($string);
        file_put_contents("scraping.xhtml", str_replace("//]]>//]]>", "//]]>", file_get_contents("scraping.xhtml")));
        file_put_contents("scraping.xhtml", str_replace("// ]]> //]]>", "//]]>", file_get_contents("scraping.xhtml")));
        file_put_contents("scraping.xhtml", str_replace("&nbsp", " ", file_get_contents("scraping.xhtml")));
        file_put_contents("scraping.xhtml", str_replace("&copy", "", file_get_contents("scraping.xhtml")));
         file_put_contents("scraping.xhtml", str_replace("&eacute", "è", file_get_contents("scraping.xhtml")));
        file_put_contents("scraping.xhtml", str_replace("&agrave", "à", file_get_contents("scraping.xhtml")));
        $xml = simplexml_load_file("scraping.xhtml");
    
        $rime = $xml->xpath("/*[name()='html']/*[name()='body']/*[name()='div'][9]/*[name()='div']/*[name()='div']/*[name()='div'][2]/*[name()='div'][1]/*[name()='div'][2]/*[name()='div']/*[name()='a']/text()");
        
        file_put_contents($FileNameXml,"\t<modi_di_dire>\n", FILE_APPEND);
        foreach ($rime as $value) {
            $value = str_replace("()", "", $value);
            $value = preg_replace('/\s+/',' ', $value);
            file_put_contents($FileNameXml,"\t\t<modo_di_dire>\n" , FILE_APPEND);
            file_put_contents($FileNameXml,"\t\t\t" . $value . "\n" , FILE_APPEND);
            file_put_contents($FileNameXml,"\t\t</modo_di_dire>\n" , FILE_APPEND);
        }
        file_put_contents($FileNameXml,"\t</modi_di_dire>\n" , FILE_APPEND);
    }
?>