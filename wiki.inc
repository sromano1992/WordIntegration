<?php
    include('wiki_api/php/functions.php');
    
    function get_http_response_code($url) {
        $headers = get_headers($url);
        return substr($headers[0], 9, 3);
    }
    
    function wiki($toSearch, $lang, $FileNameXml){
        error_reporting(0);
        $toSearch = ucfirst($toSearch);
        
        ## About to start the scrapping from this point
        $url = 'http://'.$lang.'.wikipedia.org/wiki/'.$toSearch;
        if(get_http_response_code($url) != "404"){
            $html = file_get_contents($url);
            $info = get_text($html);
            
            ## Cleaning the fetched description tag
            $info = strip_tags($info);
            $info = clean_input($info);
            $info = explode("\n", $info);
            file_put_contents($FileNameXml,"\t<wiki>\n" , FILE_APPEND);
            $oldLine = " ";
            foreach ($info as $v) {
                if($v == "" && $oldLine == "")
                    continue;
                $oldLine = $v;
                file_put_contents($FileNameXml,"\t\t<line>\n", FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t\t" . $v . "\n" , FILE_APPEND);
                file_put_contents($FileNameXml,"\t\t</line>\n", FILE_APPEND);
            }
            file_put_contents($FileNameXml,"\t</wiki>\n" , FILE_APPEND);
            
            ## Clear the parser
            $info = null;
            $html = null;
        }else{
            $html = "Wiki result not found...";
            file_put_contents($FileNameXml,"\t<wiki>\n" , FILE_APPEND);
            file_put_contents($FileNameXml,"\t\t Wiki result not found... \n" , FILE_APPEND);
            file_put_contents($FileNameXml,"\t</wiki>\n" , FILE_APPEND);
        }
        
    }
?>