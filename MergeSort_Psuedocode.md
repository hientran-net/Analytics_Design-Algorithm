// Psuedocode for Merge function:

FUNCTION merge(a[], left, middle, right)
    // Tạo hai mảng con từ mảng chính
    DECLARE firstArray AS ARRAY OF INTEGER FROM a[left] TO [middle]
    DECLARE secondArray AS ARRAY OF INTEGER FROM a[middle + 1] TO a[right]

    SET i = 0                // Chỉ số cho firstArray
    SET j = 0                // Chỉ số cho secondArray

    // Gộp các mảng con vào mảng chính
    WHILE i < SIZE(firstArray) AND j < SIZE(secondArray) DO
        IF firstArray[i] <= secondArray[j] THEN
            a[left] = firstArray[i]
            INCREMENT left
            INCREMENT i
        ELSE
            a[left] = secondArray[j]
            INCREMENT left
            INCREMENT j
        END IF
    END WHILE

    // Sao chép các phần tử còn lại của firstArray (nếu có)
    WHILE i < SIZE(firstArray) DO
        a[left] = firstArray[i]
        INCREMENT left
        INCREMENT i
    END WHILE

    // Sao chép các phần tử còn lại của secondArray (nếu có)
    WHILE j < SIZE(secondArray) DO
        a[left] = secondArray[j]
        INCREMENT left
        INCREMENT j
    END WHILE
END FUNCTION

// Psuedocode for MergeSort function:

MergeSort(A, left, right):
    if left >= right:
        return
    middle = ( left + right ) / 2

    mergeSort(A, left, middle)
    mergeSort(A, middle + 1, right)
    merge(A, left, middle, right)