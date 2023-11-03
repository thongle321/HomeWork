<?php
class DB
{
    private static $host = "localhost";
    private static $username = "root";
    private static $password = "";
    private static $dbname = "sanpham";

    private static function connectDB()
    {
        try {

            $conn = new PDO('mysql:host="' . DB::$host . ';dbname=' . DB::$dbname, DB::$username, DB::$password);
            // thiết lập khi xảy ra lỗi thì tạo ra ngoại lệ (exeption) ​
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
            echo "Kết nối CSDL thất bại: " . $e->getMessage();
            exit;
        }
        return $conn;
    }
    public static function read($sql, $params=[])
    {
        $result = [];
        $conn = DB::connectDB();
        try
        {
            $stmt = $conn->prepare($sql);
            foreach ($params as $key => $value)
            {
                
            }
            #code
        }
        $stmt->execute();
        $stmt->setFetchMode(PDO::FETCH_ASSOC);

        $result = $stmt->fetchAll();
    } 
    catch(PDOException $e)
    {
        echo "Loi: " . $e->getMessage();
    }
    $conn = NULL;
    return $result;
}