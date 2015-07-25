<?php
function traduci($parola, $da, $a, $FileNameXml){
    include "Google_Translator_Class.php";
    $obj = new GoogleTranslate($da, $a);
    file_put_contents($FileNameXml,"\t<traduzioni>\n", FILE_APPEND);
    file_put_contents($FileNameXml,"\t\t<traduzione da=\"".$da."\" a=\"".$a."\">\n" , FILE_APPEND);
    file_put_contents($FileNameXml,"\t\t\t\t" . $obj->translate($parola) . "\n" , FILE_APPEND);
    file_put_contents($FileNameXml,"\t\t</traduzione>\n" , FILE_APPEND);
    file_put_contents($FileNameXml,"\t</traduzioni>\n", FILE_APPEND);
}
?>