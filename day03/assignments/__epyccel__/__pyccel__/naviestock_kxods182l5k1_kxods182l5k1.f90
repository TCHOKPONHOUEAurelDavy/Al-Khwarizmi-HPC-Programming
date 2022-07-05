module naviestock_kxods182l5k1_kxods182l5k1


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine build_up_b_numba(b, rho, dt, u, v, dx, dy) 

    implicit none

    real(f64), intent(inout) :: b(0:,0:)
    real(f64), value :: rho
    real(f64), value :: dt
    real(f64), intent(in) :: u(0:,0:)
    real(f64), intent(in) :: v(0:,0:)
    real(f64), value :: dx
    real(f64), value :: dy

    !$omp parallel
    b(1_i64:size(b, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(b, 2_i64, &
          i64) - 1_i64 - 1_i64) = rho * (1_i64 / dt * ((u(2_i64:, 1_i64 &
          :size(u, 2_i64, i64) - 1_i64 - 1_i64) - u(0_i64:size(u, 1_i64 &
          , i64) - 2_i64 - 1_i64, 1_i64:size(u, 2_i64, i64) - 1_i64 - &
          1_i64)) / (2_i64 * dx) + (v(1_i64:size(v, 1_i64, i64) - 1_i64 &
          - 1_i64, 2_i64:) - v(1_i64:size(v, 1_i64, i64) - 1_i64 - &
          1_i64, 0_i64:size(v, 2_i64, i64) - 2_i64 - 1_i64)) / (2_i64 * &
          dy)) - ((u(2_i64:, 1_i64:size(u, 2_i64, i64) - 1_i64 - 1_i64 &
          ) - u(0_i64:size(u, 1_i64, i64) - 2_i64 - 1_i64, 1_i64:size(u &
          , 2_i64, i64) - 1_i64 - 1_i64)) / (2_i64 * dx)) ** 2_i64 - &
          2_i64 * ((u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 2_i64: &
          ) - u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 0_i64:size(u &
          , 2_i64, i64) - 2_i64 - 1_i64)) / (2_i64 * dy) * (v(2_i64:, &
          1_i64:size(v, 2_i64, i64) - 1_i64 - 1_i64) - v(0_i64:size(v, &
          1_i64, i64) - 2_i64 - 1_i64, 1_i64:size(v, 2_i64, i64) - &
          1_i64 - 1_i64)) / (2_i64 * dx)) - ((v(1_i64:size(v, 1_i64, &
          i64) - 1_i64 - 1_i64, 2_i64:) - v(1_i64:size(v, 1_i64, i64) - &
          1_i64 - 1_i64, 0_i64:size(v, 2_i64, i64) - 2_i64 - 1_i64)) / &
          (2_i64 * dy)) ** 2_i64)
    !$omp end parallel

  end subroutine build_up_b_numba
  !........................................

  !........................................
  subroutine pressure_poisson_numba(p, dx, dy, b, nit, nt) 

    implicit none

    real(f64), intent(inout) :: p(0:,0:)
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), intent(in) :: b(0:,0:)
    integer(i64), value :: nit
    integer(i64), value :: nt
    integer(i64) :: row
    integer(i64) :: col
    real(f64), allocatable :: pn(:,:)
    integer(i64) :: q
    integer(i64) :: i
    integer(i64) :: j

    row = size(p, 2_i64, i64)
    col = size(p, 1_i64, i64)
    allocate(pn(0:size(p, 1_i64, i64) - 1_i64, 0:size(p, 2_i64, i64) - &
          1_i64))
    !$omp parallel
    !$omp do
    do q = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, row - 1_i64, 1_i64
        do j = 0_i64, col - 1_i64, 1_i64
          pn(j, i) = p(j, i)
        end do
      end do
      do i = 1_i64, row - 1_i64 - 1_i64, 1_i64
        do j = 1_i64, col - 1_i64 - 1_i64, 1_i64
          p(j, i) = ((pn(j, i + 1_i64) + pn(j, i - 1_i64)) * dy ** 2_i64 &
                + (pn(j + 1_i64, i) + pn(j - 1_i64, i)) * dx ** 2_i64) &
                / (2_i64 * (dx ** 2_i64 + dy ** 2_i64)) - dx ** 2_i64 * &
                dy ** 2_i64 / (2_i64 * (dx ** 2_i64 + dy ** 2_i64)) * b &
                (j, i)
        end do
      end do
    end do
    !$omp end do
    p(size(p, 1_i64, i64) - 1_i64, :) = p(size(p, 1_i64, i64) - 2_i64, : &
          )
    p(:, 0_i64) = p(:, 1_i64)
    p(0_i64, :) = p(1_i64, :)
    p(:, size(p, 2_i64, i64) - 1_i64) = 0_i64
    !$omp end parallel
    if (allocated(pn)) then
      deallocate(pn)
    end if

  end subroutine pressure_poisson_numba
  !........................................

  !........................................
  subroutine cavity_flow_numba(u, v, dt, nx, ny, dx, dy, p, rho, nu, nit &
        , nt)

    implicit none

    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: v(0:,0:)
    real(f64), value :: dt
    integer(i64), value :: nx
    integer(i64), value :: ny
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), intent(inout) :: p(0:,0:)
    real(f64), value :: rho
    real(f64), value :: nu
    integer(i64), value :: nit
    integer(i64), value :: nt
    integer(i64) :: row1
    integer(i64) :: col1
    integer(i64) :: row2
    integer(i64) :: col2
    real(f64), allocatable :: un(:,:)
    real(f64), allocatable :: vn(:,:)
    real(f64), allocatable :: b(:,:)
    integer(i64) :: n
    integer(i64) :: i
    integer(i64) :: j

    row1 = size(u, 2_i64, i64)
    col1 = size(u, 1_i64, i64)
    row2 = size(v, 2_i64, i64)
    col2 = size(v, 1_i64, i64)
    allocate(un(0:size(u, 1_i64, i64) - 1_i64, 0:size(u, 2_i64, i64) - &
          1_i64))
    allocate(vn(0:size(v, 1_i64, i64) - 1_i64, 0:size(v, 2_i64, i64) - &
          1_i64))
    allocate(b(0:nx - 1_i64, 0:ny - 1_i64))
    !$omp parallel
    !$omp do
    do n = 0_i64, nt - 1_i64, 1_i64
      do i = 0_i64, row1 - 1_i64, 1_i64
        do j = 0_i64, col1 - 1_i64, 1_i64
          un(j, i) = u(j, i)
        end do
      end do
      do i = 0_i64, row2 - 1_i64, 1_i64
        do j = 0_i64, col2 - 1_i64, 1_i64
          vn(j, i) = v(j, i)
        end do
      end do
      call build_up_b_numba(b, rho, dt, u, v, dx, dy)
      call pressure_poisson_numba(p, dx, dy, b, nit, nt)
      u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(u, 2_i64, &
            i64) - 1_i64 - 1_i64) = un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) &
            - un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size &
            (un, 2_i64, i64) - 1_i64 - 1_i64) * dt / dx * (un(1_i64: &
            size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64, &
            i64) - 1_i64 - 1_i64) - un(0_i64:size(un, 1_i64, i64) - &
            2_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64 &
            )) - vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64: &
            size(vn, 2_i64, i64) - 1_i64 - 1_i64) * dt / dy * (un(1_i64 &
            :size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64 &
            , i64) - 1_i64 - 1_i64) - un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(un, 2_i64, i64) - 2_i64 - 1_i64 &
            )) - dt / (2_i64 * rho * dx) * (p(2_i64:, 1_i64:size(p, &
            2_i64, i64) - 1_i64 - 1_i64) - p(0_i64:size(p, 1_i64, i64) &
            - 2_i64 - 1_i64, 1_i64:size(p, 2_i64, i64) - 1_i64 - 1_i64 &
            )) + nu * (dt / dx ** 2_i64 * (un(2_i64:, 1_i64:size(un, &
            2_i64, i64) - 1_i64 - 1_i64) - 2_i64 * un(1_i64:size(un, &
            1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - &
            1_i64 - 1_i64) + un(0_i64:size(un, 1_i64, i64) - 2_i64 - &
            1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64)) + dt / &
            dy ** 2_i64 * (un(1_i64:size(un, 1_i64, i64) - 1_i64 - &
            1_i64, 2_i64:) - 2_i64 * un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) &
            + un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 0_i64:size &
            (un, 2_i64, i64) - 2_i64 - 1_i64)))
      v(1_i64:size(v, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(v, 2_i64, &
            i64) - 1_i64 - 1_i64) = vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) &
            - un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size &
            (un, 2_i64, i64) - 1_i64 - 1_i64) * dt / dx * (vn(1_i64: &
            size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64, &
            i64) - 1_i64 - 1_i64) - vn(0_i64:size(vn, 1_i64, i64) - &
            2_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64 &
            )) - vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64: &
            size(vn, 2_i64, i64) - 1_i64 - 1_i64) * dt / dy * (vn(1_i64 &
            :size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64 &
            , i64) - 1_i64 - 1_i64) - vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(vn, 2_i64, i64) - 2_i64 - 1_i64 &
            )) - dt / (2_i64 * rho * dy) * (p(1_i64:size(p, 1_i64, i64 &
            ) - 1_i64 - 1_i64, 2_i64:) - p(1_i64:size(p, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(p, 2_i64, i64) - 2_i64 - 1_i64)) &
            + nu * (dt / dx ** 2_i64 * (vn(2_i64:, 1_i64:size(vn, 2_i64 &
            , i64) - 1_i64 - 1_i64) - 2_i64 * vn(1_i64:size(vn, 1_i64, &
            i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - &
            1_i64) + vn(0_i64:size(vn, 1_i64, i64) - 2_i64 - 1_i64, &
            1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64)) + dt / dy ** &
            2_i64 * (vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, &
            2_i64:) - 2_i64 * vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - &
            1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) + vn( &
            1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 0_i64:size(vn, &
            2_i64, i64) - 2_i64 - 1_i64)))
      u(:, 0_i64) = 0_i64
      u(0_i64, :) = 0_i64
      u(size(u, 1_i64, i64) - 1_i64, :) = 0_i64
      u(:, size(u, 2_i64, i64) - 1_i64) = 1_i64
      v(:, 0_i64) = 0_i64
      v(:, size(v, 2_i64, i64) - 1_i64) = 0_i64
      v(0_i64, :) = 0_i64
      v(size(v, 1_i64, i64) - 1_i64, :) = 0_i64
    end do
    !$omp end do
    !$omp end parallel
    if (allocated(un)) then
      deallocate(un)
    end if
    if (allocated(vn)) then
      deallocate(vn)
    end if
    if (allocated(b)) then
      deallocate(b)
    end if

  end subroutine cavity_flow_numba
  !........................................

end module naviestock_kxods182l5k1_kxods182l5k1
