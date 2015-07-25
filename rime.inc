<?php
    function rime($parola, $FileNameXml){
        shell_exec("curl http://www.cercarime.it/?rima=" . $parola . " > scraping.html");
        $string = "curl --data-binary @scraping.html -H \"Content-Type: text/html\"  http://www.it.uc3m.es/jaf/cgi-bin/html2xhtml.cgi > scraping.xhtml";
        shell_exec($string);
    
        #parsing del documento per togliere eventuali caratteri che fanno sbombare il DOM
        //file_put_contents("scraping.xhtml", str_replace("&copy", "", file_get_contents("scraping.xhtml")));
        //file_put_contents("scraping.xhtml", str_replace("&eacute", "è", file_get_contents("scraping.xhtml")));
        $xml = simplexml_load_file("scraping.xhtml");
    
        $rime = $xml->xpath("//*[name()='div']/*[name()='div'][1]/*[name()='ul'][1]/*[name()='li']/*[name()='p']/*[name()='i']/*[name()='a']/text()");
        
        if(count($rime)==0){
            file_put_contents($FileNameXml,"\t<rime>\n", FILE_APPEND);
            file_put_contents($FileNameXml,"\t\t<warning>\n", FILE_APPEND);
            file_put_contents($FileNameXml,"\t\t\t Nessuna rima trovata \n" , FILE_APPEND);
            file_put_contents($FileNameXml,"\t\t</warning>\n" , FILE_APPEND);
            file_put_contents($FileNameXml,"\t</rime>\n" , FILE_APPEND);
        }
        else{
            file_put_contents($FileNameXml,"\t<rime>\n", FILE_APPEND);
            foreach ($rime as $value) {
                file_put_contents($FileNameXml,"\t\t<rima>\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t" . $value . "\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</rima>\n" , FILE_APPEND);
            }
            file_put_contents($FileNameXml,"\t</rime>\n" , FILE_APPEND);
        }
    }        
?>