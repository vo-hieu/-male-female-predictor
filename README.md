<h1> Dự đoán giới tính dựa vào chiều cao và cân nặng </h1>
  <h3> Danh sách các files: </h3>
  <h5> male_female_predictor.cpp: Chương trình chính dùng để dự đoán. </h5>
  <h5> TestAccuracy.cpp: Dùng để kiểm tra độ chính xác của thuật toán. </h5>
  <h5> TrainSet.csv: Dữ liệu dùng để train. </h5>
  <h5> TestSet.csv: Dữ liệu dùng để test độ chính xác. </h5>
  <h5> data.txt: Được convert từ TrainSet.csv để dễ dàng sử dụng. </h5>
  <h5> testset.txt: File convert từ TestSet.csv. </h5>
  
<h1> Thuật toán: </h1>
<p> Chương trình sử dụng thuật toán Naive Bayes, mô hình Gaussian. </p>
<p> Công thức Naive Bayes, xác suất có điều kiện: </p>
<img src = "https://github.com/vo-hieu/male-female-predictor/blob/master/Images/Bayes_rule.png" />

<h1> Chạy chương trình: </h1>
<img src = "https://github.com/vo-hieu/male-female-predictor/blob/master/Images/run1.png" />
<img src = "https://github.com/vo-hieu/male-female-predictor/blob/master/Images/run2.png" />

<h1> Test độ chính xác của mô hình: </h1>
Chạy file TestAccuracy lên để test. TestAccuracy sẽ chạy file male-female-predictor.exe với input từ testset.txt và lấy output rồi so khớp với testset.txt.
<img src = "https://github.com/vo-hieu/male-female-predictor/blob/master/Images/test.png" />
<b> Kết quả: 48.8% </b>
<i> Test thử với dataset dùng để train (data.txt) ---> ~90% </i>
<p> ----> Thuật toán cùi bắp. </p>
<p> -------> Nguyên nhân: TestSet chưa chuẩn. </p>
<b> Kết luận: Xác định giới tính dựa vào chiều cao và cân nặng là không khả thi. Side project này được post với mục đích học tập. </b>
