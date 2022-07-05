module naviestock_j8hquxbllq4o_j8hquxbllq4o


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function build_up_b_numba(b, rho, dt, u, v, dx, dy) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
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
    Out_0001 = 0_i64
    return

  end function build_up_b_numba
  !........................................

  !........................................
  function pressure_poisson_numba(p, dx, dy, b, nit, nt) result(Out_0002 &
        )

    implicit none

    integer(i64) :: Out_0002
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
    do q = 0_i64, nit - 1_i64, 1_i64
      pn(:, :) = p(:, :)
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
    Out_0002 = 0_i64
    if (allocated(pn)) then
      deallocate(pn)
    end if
    return

  end function pressure_poisson_numba
  !........................................

  !........................................
  function cavity_flow_numba(u, v, dt, nx, ny, dx, dy, p, rho, nu, nit, &
        nt) result(Out_0003)

    implicit none

    integer(i64) :: Out_0003
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
    real(f64), allocatable :: un(:,:)
    real(f64), allocatable :: vn(:,:)
    real(f64), allocatable :: b(:,:)
    integer(i64) :: n
    integer(i64) :: Dummy_0001
    integer(i64) :: Dummy_0002

    allocate(un(0:size(u, 1_i64, i64) - 1_i64, 0:size(u, 2_i64, i64) - &
          1_i64))
    allocate(vn(0:size(v, 1_i64, i64) - 1_i64, 0:size(v, 2_i64, i64) - &
          1_i64))
    allocate(b(0:nx - 1_i64, 0:ny - 1_i64))
    !$omp parallel
    !$omp do
    do n = 0_i64, nt - 1_i64, 1_i64
      un(:, :) = u(:, :)
      vn(:, :) = v(:, :)
      Dummy_0001 = build_up_b_numba(b, rho, dt, u, v, dx, dy)
      Dummy_0002 = pressure_poisson_numba(p, dx, dy, b, nit, nt)
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
    end do
    !$omp end do
    !$omp sections
    !$omp section
    u(:, 0_i64) = 0_i64
    u(0_i64, :) = 0_i64
    u(size(u, 1_i64, i64) - 1_i64, :) = 0_i64
    u(:, size(u, 2_i64, i64) - 1_i64) = 1_i64
    !$omp section
    v(:, 0_i64) = 0_i64
    v(:, size(v, 2_i64, i64) - 1_i64) = 0_i64
    v(0_i64, :) = 0_i64
    v(size(v, 1_i64, i64) - 1_i64, :) = 0_i64
    !$omp end sections nowait
    !$omp end parallel
    Out_0003 = 0_i64
    if (allocated(un)) then
      deallocate(un)
    end if
    if (allocated(vn)) then
      deallocate(vn)
    end if
    if (allocated(b)) then
      deallocate(b)
    end if
    return

  end function cavity_flow_numba
  !........................................

end module naviestock_j8hquxbllq4o_j8hquxbllq4o
