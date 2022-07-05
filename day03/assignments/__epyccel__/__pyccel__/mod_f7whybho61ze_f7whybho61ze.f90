module mod_f7whybho61ze_f7whybho61ze


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  recursive function strassen_multiply(A, B, C, n) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(in), target :: A(0:,0:)
    real(f64), intent(in), target :: B(0:,0:)
    real(f64), intent(inout) :: C(0:,0:)
    integer(i64), value :: n
    integer(i64) :: n2
    real(f64), pointer :: A11(:,:)
    real(f64), pointer :: A21(:,:)
    real(f64), pointer :: A12(:,:)
    real(f64), pointer :: A22(:,:)
    real(f64), pointer :: B11(:,:)
    real(f64), pointer :: B21(:,:)
    real(f64), pointer :: B12(:,:)
    real(f64), pointer :: B22(:,:)
    real(f64), allocatable :: Q1(:,:)
    real(f64), allocatable :: Q2(:,:)
    real(f64), allocatable :: Q3(:,:)
    real(f64), allocatable :: Q4(:,:)
    real(f64), allocatable :: Q5(:,:)
    real(f64), allocatable :: Q6(:,:)
    real(f64), allocatable :: Q7(:,:)
    integer(i64) :: Dummy_0001
    integer(i64) :: Dummy_0002
    integer(i64) :: Dummy_0003
    integer(i64) :: Dummy_0004
    integer(i64) :: Dummy_0005
    integer(i64) :: Dummy_0006
    integer(i64) :: Dummy_0007

    !A11 float[:]
    !$omp parallel
    if (IAND(n, 1_i64) /= 0_i64 .or. n < 128_i64) then
      C(:, :) = matmul(B,A)
    else
      n2 = FLOOR(n/2.0_f64,i64)
      A11(0:, 0:) => A(0_i64:n2 - 1_i64, 0_i64:n2 - 1_i64)
      A21(0:, 0:) => A(0_i64:n2 - 1_i64, n2:n - 1_i64)
      A12(0:, 0:) => A(n2:n - 1_i64, 0_i64:n2 - 1_i64)
      A22(0:, 0:) => A(n2:n - 1_i64, n2:n - 1_i64)
      B11(0:, 0:) => B(0_i64:n2 - 1_i64, 0_i64:n2 - 1_i64)
      B21(0:, 0:) => B(0_i64:n2 - 1_i64, n2:n - 1_i64)
      B12(0:, 0:) => B(n2:n - 1_i64, 0_i64:n2 - 1_i64)
      B22(0:, 0:) => B(n2:n - 1_i64, n2:n - 1_i64)
      allocate(Q1(0:n2 - 1_i64, 0:n2 - 1_i64))
      allocate(Q2(0:n2 - 1_i64, 0:n2 - 1_i64))
      allocate(Q3(0:n2 - 1_i64, 0:n2 - 1_i64))
      allocate(Q4(0:n2 - 1_i64, 0:n2 - 1_i64))
      allocate(Q5(0:n2 - 1_i64, 0:n2 - 1_i64))
      allocate(Q6(0:n2 - 1_i64, 0:n2 - 1_i64))
      allocate(Q7(0:n2 - 1_i64, 0:n2 - 1_i64))
      Dummy_0001 = strassen_multiply(A11 + A22, B11 + B22, Q1, n2)
      Dummy_0002 = strassen_multiply(A21 + A22, B11, Q2, n2)
      Dummy_0003 = strassen_multiply(A11, B12 - B22, Q3, n2)
      Dummy_0004 = strassen_multiply(A22, (-B11) + B21, Q4, n2)
      Dummy_0005 = strassen_multiply(A11 + A12, B22, Q5, n2)
      Dummy_0006 = strassen_multiply((-A11) + A21, B11 + B12, Q6, n2)
      Dummy_0007 = strassen_multiply(A12 - A22, B21 + B22, Q7, n2)
      C(:n2 - 1_i64, :n2 - 1_i64) = Q1 + Q4 - Q5 + Q7
      C(:n2 - 1_i64, n2:n - 1_i64) = Q2 + Q4
      C(n2:n - 1_i64, :n2 - 1_i64) = Q3 + Q5
      C(n2:n - 1_i64, n2:n - 1_i64) = Q1 + Q3 - Q2 + Q6
    end if
    !$omp end parallel
    Out_0001 = 0_i64
    if (allocated(Q1)) then
      deallocate(Q1)
    end if
    if (allocated(Q2)) then
      deallocate(Q2)
    end if
    if (allocated(Q3)) then
      deallocate(Q3)
    end if
    if (allocated(Q4)) then
      deallocate(Q4)
    end if
    if (allocated(Q5)) then
      deallocate(Q5)
    end if
    if (allocated(Q6)) then
      deallocate(Q6)
    end if
    if (allocated(Q7)) then
      deallocate(Q7)
    end if
    return

  end function strassen_multiply
  !........................................

end module mod_f7whybho61ze_f7whybho61ze
