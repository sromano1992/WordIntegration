<?php    

    function check($sinonimi, $contrari){
        if(isset($sinonimi) && isset($contrari))
            return 1;
        if(isset($sinonimi))
            return 2;
        if(isset($contrari))
            return 3;
    }
    function sinonimi_contrari($parola, $FileNameXml, $val){

        shell_exec("curl http://www.sinonimi-contrari.it/".$parola."/ > scraping.html");
        $string = "curl --data-binary @scraping.html -H \"Content-Type: text/html\"  http://www.it.uc3m.es/jaf/cgi-bin/html2xhtml.cgi > scraping.xhtml";
        shell_exec($string);
    
        #parsing del documento per togliere eventuali caratteri che fanno sbombare il DOM
        file_put_contents("scraping.xhtml", str_replace("&copy", "", file_get_contents("scraping.xhtml")));
        file_put_contents("scraping.xhtml", str_replace("&eacute", "è", file_get_contents("scraping.xhtml")));
        $xml = simplexml_load_file("scraping.xhtml");
    
        $sinonimi = $xml->xpath("/*[name()='html']/*[name()='body']/*[name()='div']/*[name()='div']/*[name()='div']/*[name()='div'][1]/*[name()='ol']/*[name()='li']/*[name()='span']/*[name()='a']/text()");
        $contrari = $xml->xpath("/*[name()='html']/*[name()='body']/*[name()='div']/*[name()='div']/*[name()='div']/*[name()='div'][3]/*[name()='ol']/*[name()='li']/*[name()='span']/*[name()='a']/text()");
        
        if($val == 1){    
            if(count($sinonimi) == 0){
                file_put_contents($FileNameXml,"\t<sinonimi>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t<warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t Nessun sinonimo trovato \n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t</sinonimi>\n" , FILE_APPEND);
            }
            else{
                file_put_contents($FileNameXml,"\t<sinonimi>\n", FILE_APPEND);
                foreach ($sinonimi as $value) {
                    file_put_contents($FileNameXml,"\t\t<sinonimo>\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t\t" . $value . "\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t</sinonimo>\n" , FILE_APPEND);
                }
                file_put_contents($FileNameXml,"\t</sinonimi>\n" , FILE_APPEND);
            }
            if(count($contrari) == 0){
                file_put_contents($FileNameXml,"\t<contrari>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t<warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t Nessun contrario trovato \n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t</contrari>\n" , FILE_APPEND);
            }
            else{
                file_put_contents($FileNameXml,"\t<contrari>\n" , FILE_APPEND);
                foreach ($contrari as $value) {
                    file_put_contents($FileNameXml,"\t\t<contrario>\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t\t" . $value . "\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t</contrario>\n" , FILE_APPEND);
                }
                file_put_contents($FileNameXml,"\t</contrari>\n" , FILE_APPEND);
            }
        }

        elseif ($val == 2) {
            if(count($sinonimi) == 0){
                file_put_contents($FileNameXml,"\t<sinonimi>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t<warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t Nessun sinonimo trovato \n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t</sinonimi>\n" , FILE_APPEND);
            }
            else{
                file_put_contents($FileNameXml,"\t<sinonimi>\n", FILE_APPEND);
                foreach ($sinonimi as $value) {
                    file_put_contents($FileNameXml,"\t\t<sinonimo>\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t\t" . $value . "\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t</sinonimo>\n" , FILE_APPEND);
                }
                file_put_contents($FileNameXml,"\t</sinonimi>\n" , FILE_APPEND);
            }
        }
        elseif ($val == 3) {
            if(count($contrari) == 0){
                file_put_contents($FileNameXml,"\t<contrari>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t<warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t Nessun contrario trovato \n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</warning>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t</contrari>\n" , FILE_APPEND);
            }
            else{
                file_put_contents($FileNameXml,"\t<contrari>\n" , FILE_APPEND);
                foreach ($contrari as $value) {
                    file_put_contents($FileNameXml,"\t\t<contrario>\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t\t" . $value . "\n" , FILE_APPEND);
                    file_put_contents($FileNameXml,"\t\t</contrario>\n" , FILE_APPEND);
                }
                file_put_contents($FileNameXml,"\t</contrari>\n" , FILE_APPEND);
            }
        }
}?>