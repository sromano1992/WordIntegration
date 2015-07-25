<?php
function dialetti($parola, $FileNameXml){
     shell_exec("curl --data \"-session=dialetti:4F0990D71b4c628559vIBBAA4A7A&parola=". $parola . "&campo=Italiano&-nothing=Cerca\" http://www.dialettando.com/dizionario/hitlist_new.lasso > scraping.html");
    $string = "curl --data-binary @scraping.html -H \"Content-Type: text/html\"  http://www.it.uc3m.es/jaf/cgi-bin/html2xhtml.cgi > scraping.xhtml";
    shell_exec($string);

    file_put_contents("scraping.xhtml", str_replace("//]]>//]]>", "//]]>", file_get_contents("scraping.xhtml")));
    file_put_contents("scraping.xhtml", str_replace("&nbsp", " ", file_get_contents("scraping.xhtml")));
    file_put_contents("scraping.xhtml", str_replace("&copy", "", file_get_contents("scraping.xhtml")));

    #parsing del documento per togliere eventuali caratteri che fanno sbombare il DOM
    
    //file_put_contents("scraping.xhtml", str_replace("&eacute", "è", file_get_contents("scraping.xhtml")));
    $xml = simplexml_load_file("scraping.xhtml");

    $dialetti = $xml->xpath("/*[name()='html']/*[name()='body']/*[name()='center']/*[name()='table']/*[name()='tr'][5]/*[name()='td'][2]/*[name()='table']/*[name()='tr'][1]/*[name()='td'][2]/*[name()='center']/*[name()='table']/*[name()='tr']/*[name()='td']/text()");
    $count = 0;
    $flag = 0;
    file_put_contents($FileNameXml,"\t<dialetti>\n", FILE_APPEND);
    foreach ($dialetti as $value) {
        $value = trim($value);
        if($value == ""){
            $value = "-----------";
            $count = 0;
        }
        else{
            $count++;
        }
        if($count == 3){
            $value = "-----------";
            $count = 0;
        }
        if($count == 1){
            $flag = 1;
            $save = $value;
        }
        if($count == 2){
            if($flag == 1){
                file_put_contents($FileNameXml,"\t\t<dialetto>\n" , FILE_APPEND);
                 file_put_contents($FileNameXml,"\t\t\t<voce>\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t\t" . $save . "\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t</voce>\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t<localita>\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t\t" . $value . "\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t</localita>\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</dialetto>\n" , FILE_APPEND);
                //echo "LOCALITA: ". $value . "<br>";
                $flag = 0;
            }
        }
    
         
    //     file_put_contents($FileNameXml,"\t\t</rima>\n" , FILE_APPEND);
    }
    file_put_contents($FileNameXml,"\t</dialetti>\n", FILE_APPEND);
    // file_put_contents($FileNameXml,"\t</rime>\n" , FILE_APPEND);
}
?>