<?php
function wordnet_overview($parola, $FileNameXml){
    $string = "/usr/local/bin/wn ". $parola ." -over > scraping.html";
    shell_exec($string);
    $file = file_get_contents("scraping.html");
    $file = explode("\n", $file);
    if(count($file)==1){
        file_put_contents($FileNameXml,"\t<overview>\n", FILE_APPEND);
        file_put_contents($FileNameXml,"\t</overview>\n", FILE_APPEND);
        return;
    }
    #print_r($file);
    file_put_contents($FileNameXml,"\t<overview>\n", FILE_APPEND);
    
    foreach ($file as $v) {

        file_put_contents($FileNameXml,"\t\t<line>\n", FILE_APPEND);
        file_put_contents($FileNameXml,"\t\t\t" . $v . "\n" , FILE_APPEND);
        file_put_contents($FileNameXml,"\t\t</line>\n", FILE_APPEND);
    }
    file_put_contents($FileNameXml,"\t</overview>\n", FILE_APPEND);
}

function wordnet_synsn($parola, $FileNameXml){
    $string = "/usr/local/bin/wn ". $parola ." -synsn > scraping.html";
    shell_exec($string);
    $file = file_get_contents("scraping.html");
    $file = explode("\n", $file);
        if(count($file)==1){
        file_put_contents($FileNameXml,"\t<synsn>\n", FILE_APPEND);
        file_put_contents($FileNameXml,"\t</synsn>\n", FILE_APPEND);
        return;
    }
    #print_r($file);
    file_put_contents($FileNameXml,"\t<synsn>\n", FILE_APPEND);
    
    foreach ($file as $v) {
        file_put_contents($FileNameXml,"\t\t<line>\n", FILE_APPEND);
        file_put_contents($FileNameXml,"\t\t\t" . $v . "\n" , FILE_APPEND);
        file_put_contents($FileNameXml,"\t\t</line>\n", FILE_APPEND);
    }
    file_put_contents($FileNameXml,"\t</synsn>\n", FILE_APPEND);
}


?>