<?php
class DB{
    private static $host = "localhost";
    private static $username = "root";
    private static $password = "";
    private static $dbname = "phpcb";
    
    private static function connectDB(){
        try {
            $conn = new PDO('mysql:host='.DB::$host.';dbname='.DB::$dbname, DB::$username, DB::$password);
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); 
        } catch(PDOException $e) {
            echo "Kết nối CSDL thất bại: ".$e->getMessage();
            exit;
        }
        return $conn;
    }
    public static function read($sql,$params=[]) {
        $result=[];
        $conn = DB::connectDB();
        try {
            $stmt = $conn->prepare($sql);
            foreach ($params as $name => $value) {
                $stmt->bindValue($name,$value);
            }
            $stmt->execute();
            $stmt->setFetchMode(PDO::FETCH_ASSOC);
            
            $result=$stmt->fetchAll();
        } catch(PDOException $e) {
            echo "Lỗi: " . $e->getMessage();
            exit;
        } 

        $conn = NULL;
        return $result;
    }
}